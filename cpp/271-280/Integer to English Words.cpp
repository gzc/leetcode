class Solution {
public:
    string hundredStr(int num){
        vector<string> arr1={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
            "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> arr2={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string ret;
        ret=num%100<20?arr1[num%100]:arr2[(num%100)/10]+(num%10?" "+arr1[num%10]:"");
        if(num>99)ret=arr1[num/100]+" Hundred"+(num%100?" "+ret:"");
        return ret;
    }
    string numberToWords(int num) {
        string ret;
        vector<string> strarr={"Thousand","Million","Billion"};
        ret=hundredStr(num%1000);
        for(int i=0;i<3;i++){
            num/=1000;
            ret=num%1000?hundredStr(num%1000)+" "+strarr[i]+" "+ ret:ret;
        }
        while(ret.back()==' ')ret.pop_back();
        return ret.empty()?"Zero":ret;
    }
};