#include <string>
#if _HAS_CXX11
#include <regex>
#endif

bool ClockTimeUtils::InputString2Time(ClockTime& clockTime, const wchar_t* inputString)
{
    // Convert wchar_t* to std::wstring for easier parsing
    std::wstring input(inputString);
	
	// Initial validation
	if (input.empty()) {
        std::cerr << "Error: Input string is empty.\n";
        return false;
    }

    // Check if input is numeric
    try {
        std::stoi(input);
    }
	catch (const std::invalid_argument& e) {
        std::cerr << "Error: Non-numeric input.\n";
        return false;
    }
	catch (const std::out_of_range& e) {
        std::cerr << "Error: Input is out of range for an integer.\n";
        return false;
    }
	
	// Parse time from string
	int hour = 0, minute = 0;
	if (!ParseTime(input, hour, minute))
		return false;
	
	// Overflow handling
	if (minute >= 60) {
		hour += minute / 60;
		minute %= 60;
	}
	if (hour >= 24)
		hour -= 24;
    
    // Final validation
	if (hour < 24 && minute < 60) {
		clockTime.SetHour(hour);
		clockTime.SetMinute(minute);
		return true;
	}

    return false;
}

#if !_HAS_CXX11
bool ClockTimeUtils::ParseTime(std::wstring input, int& hour, int& minute)
{
	// Get input length
	int length = input.length();
	const wchar_t* inputString = input.c_str();
	
    // Case for 1 character input (e.g., "3")
    if (length == 1) {
        hour = _wstoi(inputString);	// Hour is the entire string
        minute = 0;                	// Minute is 00
        return true;
    }

    // Case for 2 character input (e.g., "08", "35")
    if (length == 2) {
        int first = _wstoi(inputString);
        int last = _wstoi(inputString + 1);

        // Handle as hour and minute if it's a valid combination
        if (first == 0 || (first > 2) || (first == 2 && last <= 3)) {
            hour = first;
            minute = last;
            return true;
        } else {
            hour = _wstoi(inputString); // Treat the whole input as hour
            minute = 0;                	// Minute is 00
            return true;
        }
    }

    // Case for 3 character input (e.g., "034", "123")
    if (length == 3) {
        int first = _wstoi(inputString);
        int firstTwo = _wstoi(inputString);
        int lastTwo = _wstoi(inputString + 1);

        if (first == 0 || firstTwo >= 24 || (lastTwo > 0 && lastTwo < 60)) {
            hour = first;
            minute = lastTwo;
            return true;
        } else {
            hour = firstTwo;
            minute = _wstoi(inputString + 2);
            return true;
        }
    }

    // Case for 4 character input (e.g., "1235", "1840")
    if (length == 4) {
        hour = _wstoi(inputString);          // First 2 digits are hour
        minute = _wstoi(inputString + 2);    // Last 2 digits are minute
        return true;
    }
	
	// Fallback if no valid format matched
    return false;
}
#else
bool ClockTimeUtils::ParseTime(std::wstring input, int& hour, int& minute)
{
    // Define regex patterns for different time formats
    std::wregex pattern1(L"^(\\d{1,2})$");    		// Matches "h" or "hh"
    std::wregex pattern2(L"^(\\d{1,2})(\\d{2})$");  // Matches "hhmm"
    std::wregex pattern3(L"^(\\d{1})(\\d{2})$");    // Matches "hmm"

    std::wsmatch match;

    // Match the input string against the patterns
    if (std::regex_match(input, match, pattern1)) {
        // Case 1: Single digit hour
        hour = std::stoi(match[1].str());
        minute = 0;
        return true;
    }
    else if (std::regex_match(input, match, pattern2)) {
        // Case 2: Two-digit hour and two-digit minute
        hour = std::stoi(match[1].str());
        minute = std::stoi(match[2].str());
        return true;
    }
    else if (std::regex_match(input, match, pattern3)) {
        // Case 3: One digit hour and two-digit minute
        hour = std::stoi(match[1].str());
        minute = std::stoi(match[2].str());
        return true;
    }

    // If no pattern matched, return false
    return false;
}
#endif