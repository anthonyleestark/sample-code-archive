// Example of event handler template for Stupid Framework:

class Button
{
	// Alias
	using EventHandler = long (*)(int, int);

	// Event handlers
	EventHandler	onClick;
	EventHandler	onDbClick;
};

class MyDialog
{
public:
	void onInit();
	static long ShowMessage_Click(int, int);
	static long ShowMessage_DoubleClick(int, int);
};

void MyDialog::onInit()
{
	// Do something in here...

	// Button event mapping
	Button btnShowMsg;
	btnShowMsg.onClick = &ShowMessage_Click;
	btnShowMsg.onDbClick = &ShowMessage_DoubleClick;
}

long MyDialog::ShowMessage_Click(int param1, int param2)
{
	// Handle clicked event
	
	return 0;
}

long MyDialog::ShowMessage_DoubleClick(int param1, int param2)
{
	// Handle double clicked event
	
	return 0;
}