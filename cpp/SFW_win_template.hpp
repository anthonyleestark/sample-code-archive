
// Window.h

// Window
class Window 
{
private:
	HWND hWnd_ = nullptr;
	HWND hParentWnd_ = nullptr;
	
public:
    // Constructor to initialize the control with a parent window
    explicit Window() {};
    virtual ~Window() = default;
	
protected:
	virtual LRESULT onCreate();
	virtual LRESULT onCommand(WPARAM wParam, LPARAM lParam);
	
public:
	HWND getHandle() const {
		return hWnd_;
	};
	
	HWND getParent() const {
		return hParentWnd_;
	};
	
public:
	virtual bool create(Window* parentWnd) {
		if (parentWnd && parentWnd->getHandle())
			hParentWnd_ = parentWnd->getHandle();
		
		// Implement more window creation here
	};
	
	virtual LRESULT WndProc(UINT msg, WPARAM wParam, LPARAM lParam) {
        switch (msg) {
		case WM_CREATE: {
			return onCreate();
		}
        case WM_COMMAND: {
            return onCommand(wParam, lParam);
        }
		
        default:
            return DefWindowProc(hWnd_, msg, wParam, lParam);
        }
	};
};

// Dialog
class Dialog : public Window 
{
private:
	unsigned dialogID_ = 0;
	
public:
    explicit Dialog(unsigned id, Window* parentWnd = nullptr) : dialogID_(id) {
		if (parentWnd && parentWnd->getHandle())
			hParentWnd_ = parentWnd->getHandle();
			
		// Implement more dialog construction here
		};
    virtual ~Dialog() = default;

private:
	virtual bool onCreate() override;
	virtual bool onSetup();
	virtual bool onInitDialog();
	
public:
	unsigned getID() const { return dialogID_; };
};

// -----------------------------------------

// Control.h

#include <functional>
#include <type_traits>
#include <utility>
#include <mem.h>

// For control Data Exchange
template <typename Type>
class DDX final 
{
private:
	Type* data_ = nullptr;
	
public:
	// Unique constructor
	explicit DDX(Type* ptr) : data_(ptr) {};
	
	// No copyable
	DDX(const DDX&) = delete;
	DDX& operator=(const DDX&) = delete;
	
	// No movable
	DDX(const DDX&&) = delete;
	DDX& operator=(const DDX&&) = delete;
	
	// Assignment
	DDX& operator=(Type* ptr) {
        data_ = ptr;
        return *this;
    };
	
	// Access value
	Type get() const {
		if (data_) return *data_;
		return Type();
	};
	void set(const Type& value) {
		// Update the referenced value
        if (data_) *data_ = value;
    };
};

// For control Event Handling
template <typename Signature>
class EventHandler;

template <typename Ret, typename... Args>
class EventHandler<Ret(Args...)> {
{
private:
	using FuncTemplate = Ret(Args...);
	using EventHandlerTemplate = std::function<FuncTemplate>;
	EventHandlerTemplate func_ = nullptr;
	
public:
    // Unique constructor
    explicit EventHandler(EventHandlerTemplate func = nullptr) : func_(func) {};
	
	// No copyable
    EventHandler(const EventHandler&) = delete;
    EventHandler& operator=(const EventHandler&) = delete;
	
	// No movable
    EventHandler(const EventHandler&&) = delete;
    EventHandler& operator=(const EventHandler&&) = delete;
	
    // Assignment (for lambdas or function pointers)
    EventHandler& operator=(EventHandlerTemplate func) {
        func_ = func;
        return *this;
    };

    // Assignment (for class member function pointers)
    template <typename T>
    EventHandler& operator=(Ret (T::*method)(Args...)) {
        func_ = std::mem_fn(method);
        return *this;
    };
	
    // Bind a member function to the event handler (using the `this` pointer)
    template <typename T>
    void bind(T* obj, Ret (T::*method)(Args...)) {
        func_ = [obj, method](Args&&... args) {
            (obj->*method)(std::forward<Args>(args)...);
        };
    };
	
	// Invoke safely, returning the result of the function if it has a return value
    Ret invoke(Args&&... args) const {
        if (func_) {
            return func_(std::forward<Args>(args)...);  // Forward args and return result
        } else {
            throw std::runtime_error("Event handler is not set.");
        }
    };
	
	// Allow function-call operator syntax
    void operator()(Args&&... args) const {
        invoke(std::forward<Args>(args)...);
    };

    // Allow boolean test
    explicit operator bool() const {
        return static_cast<bool>(func_);
    };
};

// Base control class
class Control : public Window 
{
private:
	unsigned ctrlID_;
	
public:
	// Construction
	explicit Control(unsigned id) : ctrlID_(id) {};
	virtual ~Control() = default;
	
public:
	// Initialization
	virtual bool init(Window* parentWnd) {
		if (!parentWnd || !parentWnd->getHandle()) {
			assert("Parent window not available!!!");
			return false;
		}
		
		hParentWnd_ = parentWnd->getHandle();
		hWnd_ = GetDlgItem(parentWnd->getHandle(), ctrlID_);
		if (!hWnd_) {
			assert("Control not found!!!");
			return false;
		}
		
		// Implement other initialization
		return true;
	};
};

// Defining a function pointer type for ButtonClick events
using ButtonClick = void(*)();

// Button control class
class Button : public Control 
{
public:
	DDX<bool> state;
	EventHandler<ButtonClick> click;
	
public:
	// Construction
	explicit Button(unsigned id) ctrlID_(id) {};
	virtual ~Button() = default;
	
public:
	bool isCheck() const {
		if (!hWnd_ || !IsWindow(hWnd_)) return false;
        return (SendMessage(hWnd_, BM_GETCHECK, 0, 0) == BST_CHECKED);
	};

public:
	LRESULT WndProc(UINT msg, WPARAM wParam, LPARAM lParam) override {
        switch (msg) {
        case WM_COMMAND: {
            // Handle click
            if (HIWORD(wParam) == BN_CLICKED) {
                return onClick();
            }
            break;
        }
		
        // Handle other messages if necessary
        default:
            return Control::WndProc(msg, wParam, lParam);
        }
		
        return 0;
    }
	
protected:
	LRESULT onClick() {
		bool newState = isCheck();		// Query the current state
		if (state.get() != newState)
			state.set(newState);		// Update the bound data
		
		if (click)
            click.invoke();  // Invoke the event handler
		
		return 0;
	};
};

// Checkbox control class
class Checkbox : public Button 
{
public:
	explicit Checkbox(unsigned id) ctrlID_(id) {};
	virtual ~Checkbox() = default;
};

// -----------------------------------------

// DialogA.h:

class DialogA : public Dialog 
{
private:
	// Data variables
	bool isChkEnable_ = false;
	
private:
	// Controls
	Checkbox showMsgCheck_(IDC_SHOWMSG_CHK);
	Button okButton_(IDOK);
	Button cancelButton_(IDCANCEL);

private:
	// Event handlers
	void onShowMsgCheck();
	void onOK();
	void onCancel();
	
public:
	void doSomething();
};

// -----------------------------------------

// DialogA.cpp:

bool DialogA::onCreate() {
   // Implement dialog creation
}

bool DialogA::onSetup() {
	if (!showMsgCheck_.init(this)) {
		assert("Checkbox not found!");
		return false;
	}
	
	showMsgCheck_.state = &isChkEnable_;	// DDX
	showMsgCheck_.click = &onShowMsgCheck;	// Event handler
	
	if (!okButton_.init(this)) {
		assert("OK button not found!");
		return false;
	}
	
	okButton_.click = &onOK;				// Event handler
	   
	if (!cancelButton_.init(this)) {
		assert("Cancel button not found!");
		return false;
	}
	
	cancelButton_.click = &onCancel;		// Event handler
	
	return true;
}

bool DialogA::onInitDialog() {
	// Implement dialog initialization
}

void DialogA::onShowMsgCheck() {
    // Handle checkbox state change
    if (isChkEnable_) {
        // Do something when checked
    } else {
        // Do something when unchecked
    }
}

void DialogA::onOK() {
    // Handle OK button click
}

void DialogA::onCancel() {
    // Handle Cancel button click
}

void DialogA::doSomething() {
	if (isChkEnable_) {}				// Get checkbox state from Data Exchange
	if (showMsgCheck_.isCheck()) {}		// Querry for checkbox state
}

// -----------------------------------------