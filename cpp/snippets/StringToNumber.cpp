vector<string> splitWords(string &str) {
    vector<string> words;
    string word = "";
    for (int i = 0; i <= str.length(); i++) {
        if ((str[i] == ' ' or str[i] == '-') or i >= str.length()) {
            words.push_back(word);
            word = "";
        }
        else
            word.push_back(str[i]);
    }
    return words;
}

long parse_int(string number) {
    const string units[] = {"one", "two", "three", "four", "five",
                            "six", "seven", "eight", "nine", "ten"};
    const string teens[] = {"eleven", "twelve", "thirteen", "fourteen",
                            "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const string tens[] = {"twenty", "thirty", "forty", "fifty", 
                            "sixty", "seventy", "eighty", "ninety"};
    vector<long> nums;
    long num = 0;
    vector<string> words = splitWords(number);
    for (string word: words) {
        for (int i = 0; i < 10; i++)
            if (word == units[i]) num += i + 1;
        for (int i = 0; i < 9; i++)
            if (word == teens[i]) num += i + 11;
        for (int i = 0; i < 8; i++)
            if (word == tens[i]) num += (i + 2) * 10;
        if (word == "hundred") num *= 100;
        if (word == "thousand") {
            num *= 1000;
            nums.push_back(num);
            num = 0;
        }
        if (word == "million") {
            num *= 1000000;
            nums.push_back(num);
            num = 0;
        }
    }
    nums.push_back(num);
    long result = 0;
    for (long x: nums)
        result += x;
    return result;
}

////

long parse_int(const std::string& number) {
  std::map<std::string, int> mapping = {
    {"zero", 0}, {"and", 0}, {"hundred", 100},  {"thousand", 1000}, {"million", 1000000},  
    {"one", 1}, {"two",   2}, {"three",  3}, {"four", 4}, {"five", 5}, 
    {"six", 6}, {"seven", 7}, {"eight",  8}, {"nine", 9}, {"ten", 10},
    {"eleven",  11}, {"twelve",    12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15},
    {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, 
    {"twenty",  20}, {"thirty",  30},   {"forty",    40}, {"fifty",    50}, 
    {"sixty",   60}, {"seventy", 70},   {"eighty",   80}, {"ninety", 90}
    
  };
  
  long result = 0;
  auto add = [&] (auto& w) {
    if (w.empty()) return;
    auto i = mapping[w];
    if      (i > 0 && i < 100) result += i;
    else if (i == 1000 || i == 1000000) result *= i;
    else if (i == 100) result += 99 * (result % 100);
    w = "";
  };
  
  std::string word;
  for (auto c : number) {
    if (word.size() > 0 && (c == ' ' || c == '-')) add(word);
    else word.push_back(c);
  }
  add(word);
  
  return result;
}