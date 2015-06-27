
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.






//利用自动机的方法进行验证
bool isNumber(string str) {
        int state=0, flag=0; // flag to judge the special case "."
        while(str[0]==' ')  str.erase(0,1);//delete the  prefix whitespace 
        while(str[str.length()-1]==' ') str.erase(str.length()-1, 1);//delete the suffix whitespace
        for(int i=0; i<str.length(); i++){
            if('0'<=str[i] && str[i]<='9'){
                flag=1;
                if(state<=2) state=2;
                else state=(state<=5)?5:7;
            }
            else if('+'==str[i] || '-'==str[i]){
                if(state==0 || state==3) state++;
                else return false;
            }
            else if('.'==str[i]){
                if(state<=2) state=6;
                else return false;
            }
            else if('e'==str[i]){
                if(flag&&(state==2 || state==6 || state==7)) state=3;
                else return false;
            }
            else return false;
        }
        return (state==2 || state==5 || (flag&&state==6) || state==7);
    }


//传统方法
 public boolean isNumber(String s) {  
        s = s.trim();  
        if (s.length() == 0) return false;  
        boolean hasE = false;  
        boolean hasDot = false;  
        boolean hasNumber = false;  
          
        for (int i = 0; i < s.length(); i++) {  
            // e cannot be the first character  
            if (i == 0 && s.charAt(i) == 'e') return false;  
            if (s.charAt(i) == 'e') {  
                // e cannot be replicated nor placed before number  
                if (hasE == true || hasNumber == false) {  
                    return false;  
                } else {  
                    hasE = true;  
                }  
            }   
              
            if (s.charAt(i) == '.') {  
                // '.' cannot be replicated nor placed after 'e'  
                if (hasDot == true || hasE == true) {  
                    return false;  
                } else {  
                    hasDot = true;  
                }  
            }  
            // the sign can be placed at the beginning or after 'e'  
            if (i != 0 && s.charAt(i - 1) != 'e' && (s.charAt(i) == '+' || s.charAt(i) == '-')) return false;  
              
            // no other chacraters except '+', '-', '.', and 'e'  
            if ((s.charAt(i) > '9' || s.charAt(i) < '0') && s.charAt(i) != '+' && s.charAt(i) != '-' && s.charAt(i) != '.' && s.charAt(i) != 'e')  
            return false;    
              
            // check whether numbers are included.  
            if (s.charAt(i) <= '9' && s.charAt(i) >= '0') {  
                hasNumber = true;  
            }  
        }  
        // '+', '-', and 'e' cannot be the last character  
        if (s.charAt(s.length() - 1) == '-' || s.charAt(s.length() - 1) == '+' || s.charAt(s.length() - 1) == 'e') return false;  
  
        return hasNumber;  
    }  