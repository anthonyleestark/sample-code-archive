const arr = [];
const arrObj = [];

var numberBlocks = [];

GenerateRandomArray(15, 4);
DisplayArray();

for (let i = 0; i < arr.length; i++)
    arrObj.push({key: arr[i], value: ConvertNumberToTextVI(arr[i])});

DisplayObjArray();

// Number processing

function ConvertNumberToTextEN(number) {
    const ones = ["zero" ,"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"];
    const teens = ["eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"];
    const tys = ["twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]
    let strNumber;
    if (number%100 == 0)
        strNumber = ones[Math.floor(number/100)] + " hundred";
    else if (number/100 > 0) {
        strNumber = ones[Math.floor(number/100)] + " hundred and ";
        number %= 100;
    }
    if (number <= ones.length)
            strNumber += ones[number];

    else if (number <= teens.length + 10)
        strNumber += teens[number - 11];
    else {
        if (number%10 == 0)
            strNumber += tys[(number/10) - 2];
        else
            strNumber += tys[Math.floor(number/10) - 2] + " " + ones[number%10];
    }
    return strNumber;
}

function ConvertNumberToTextVI(number) {
    const ones = ["không" ,"một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín", "mười"];
    const teens = ["mười một", "mười hai", "mười ba", "mười bốn", "mười lăm", "mười sáu", "mười bảy", "mười tám", "mười chín"];
    const tys = ["hai mươi", "ba mươi", "bốn mươi", "năm mươi", "sáu mươi", "bảy mươi", "tám mươi", "chín mươi"]
    let strNumber = "";
    flag = false;
    if (number >= 1000 && number/1000 > 0) {
        // strNumber += " nghìn ";
        strNumber = ones[Math.floor(number/1000)] + " nghìn ";
        if (Math.floor(number/100)%10 == 0)
            strNumber += "không trăm ";
        number %= 1000;
        flag = true;
    }
    if (number >= 100 && number/100 > 0) {
        strNumber += ones[Math.floor(number/100)] + " trăm ";
        number %= 100;
        flag = true;
    }
    if (number <= ones.length)
        if (flag == true)
            strNumber += "lẻ " + ones[number];
        else
            strNumber += ones[number];

    else if (number <= teens.length + 10)
        strNumber += teens[number - 11];
    else {
        if (number%10 == 0)
            strNumber += tys[(number/10) - 2];
        else
            strNumber += tys[Math.floor(number/10) - 2] + " " + ones[number%10];
    }
    strNumber = strNumber.replace(" lẻ không", "");
    strNumber = strNumber.replace("mươi năm", "mươi lăm");
    strNumber = strNumber.replace("mươi bốn", "mươi tư");
    strNumber = strNumber.replace("mươi một", "mươi mốt");
    return strNumber;
}

// Number to Vietnamese Text Full Version

function ConvertNumberToVietnamese(number) {
    let numOfBlocks = (number) => {
        let i = 0;
        while (number > 0) {
            numberBlocks.unshift((number%1000));
            number = Math.floor(number/1000);
            i++;
        }
        return numberBlocks.length;
    };
    let strResult = "";
    for (let i = 0; i < numOfBlocks; i++) {
        strResult += ConvertThreeDigitsBlock(i, numberBlocks[i]);
        switch (numOfBlocks - i) {
            case 2:
            case 5:
                strResult += " nghìn ";
                break;
            case 3:
            case 6:
                strResult += " triệu ";
                break;
            case 4:
            case 7:
                strResult += " tỷ ";
                break;
        }
    }
    numberBlocks = [];
    return strResult;
}

function ConvertThreeDigitsBlock(index, number) {
    const ones = ["không" ,"một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín", "mười"];
    const teens = ["mười một", "mười hai", "mười ba", "mười bốn", "mười lăm", "mười sáu", "mười bảy", "mười tám", "mười chín"];
    const tys = ["hai mươi", "ba mươi", "bốn mươi", "năm mươi", "sáu mươi", "bảy mươi", "tám mươi", "chín mươi"]
    let strNumber = "";
    
    flag = false;
    if (index > 0 && number < 100) {
        strNumber += "không trăm ";
        flag = true;
    }
    if (number >= 100 && number/100 > 0) {
        strNumber += ones[Math.floor(number/100)] + " trăm ";
        number %= 100;
        flag = true;
    }

    if (number <= ones.length)
        if (flag == true)
            strNumber += "lẻ " + ones[number];
        else
            strNumber += ones[number];

    else if (number <= teens.length + 10)
        strNumber += teens[number - 11];
    else {
        if (number%10 == 0)
            strNumber += tys[(number/10) - 2];
        else
            strNumber += tys[Math.floor(number/10) - 2] + " " + ones[number%10];
    }

    strNumber = strNumber.replace(" lẻ không", "");
    strNumber = strNumber.replace("mươi năm", "mươi lăm");
    strNumber = strNumber.replace("mươi bốn", "mươi tư");
    strNumber = strNumber.replace("mươi một", "mươi mốt");
    return strNumber;
}

// Array methods

function GenerateRandomArray(numberOfElements, numberOfDigits) {
    for (let i = 0; i < numberOfElements; i++)
        arr.push(Math.floor(Math.random()*(10**numberOfDigits)));
}

function DisplayArray() {
    let strResult = "Your array: ";
    for (let i = 0; i < arr.length - 1; i++)
        strResult += arr[i] + ", ";
    strResult += arr[arr.length - 1] + ".";
    console.log(strResult);
}

function DisplayObjArray() {
    let strResult = "Your array: ";
    for (let i = 0; i < arrObj.length - 1; i++)
        strResult += arrObj[i].key + " (" + arrObj[i].value + "), ";
    strResult += arrObj[arrObj.length - 1].key + " (" + arrObj[arrObj.length - 1].value + ").";
    console.log(strResult);
}