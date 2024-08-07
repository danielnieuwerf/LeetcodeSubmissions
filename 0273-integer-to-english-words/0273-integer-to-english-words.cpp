class Solution {
public:
    string numberToWords(int num) {
        if(num/1000000000 > 0) return num%1000000000==0 ? numberToWords(num/1000000000) + " Billion" : numberToWords(num/1000000000) + " Billion " + numberToWords(num%1000000000);
        if(num/1000000 > 0) return num%1000000==0 ? numberToWords(num/1000000) + " Million" : numberToWords(num/1000000) + " Million " + numberToWords(num%1000000);        
        if(num/1000 > 0) return num%1000==0 ? numberToWords(num/1000) + " Thousand" : numberToWords(num/1000) + " Thousand " + numberToWords(num%1000);        
        if(num/100 > 0) return num%100==0 ? numberToWords(num/100) + " Hundred" : numberToWords(num/100) + " Hundred " + numberToWords(num%100);        
        if(num/90 > 0) return num==90 ? "Ninety" : "Ninety " + numberToWords(num%90);
        if(num/80 > 0) return num==80 ? "Eighty": "Eighty " + numberToWords(num%80);        
        if(num/70 > 0) return num==70 ? "Seventy": "Seventy " + numberToWords(num%70);        
        if(num/60 > 0) return num==60 ? "Sixty" : "Sixty " + numberToWords(num%60);        
        if(num/50 > 0) return num==50 ? "Fifty" : "Fifty " + numberToWords(num%50);
        if(num/40 > 0) return num==40 ? "Forty" : "Forty " + numberToWords(num%40);        
        if(num/30 > 0) return num==30 ? "Thirty" : "Thirty " + numberToWords(num%30);        
        if(num/20 > 0) return num==20 ? "Twenty": "Twenty " + numberToWords(num%20);        
        switch(num)
        {
            case 19: return "Nineteen";
            case 18: return "Eighteen";
            case 17: return "Seventeen";
            case 16: return "Sixteen";
            case 15: return "Fifteen";
            case 14: return "Fourteen";
            case 13: return "Thirteen";
            case 12: return "Twelve";
            case 11: return "Eleven";
            case 10: return "Ten";
            case 9: return "Nine";
            case 8: return "Eight";
            case 7: return "Seven";
            case 6: return "Six";
            case 5: return "Five";
            case 4: return "Four";
            case 3: return "Three";
            case 2: return "Two";
            case 1: return "One";
        }

        return "Zero";
    }

};