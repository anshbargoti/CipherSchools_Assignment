class Solution {
public:
    int getPrecedence( char optr){
        if(optr == '+' || optr == '-')
            return 1;
        if(optr == '*' || optr == '/')
        return 2;
        return 0;
    }

    int applyOperation (int a, int b, char op){
        switch (op)
        {
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                return a/b;
            default:
                return 0;
        }
    }

    int evaluateExp(string exp){
        int i;
        stack<int> value;
        stack<char> optr;

        for(i=0 ; i < exp.length(); i++)
        {
            if(exp[i] == ' ')
                continue;
            else if(exp[i] == '(')
            {
                optr.push(exp[i]);
            }
            else if(isdigit(exp[i])){
                int val = 0;
                while(i<exp.length() && isdigit(exp[i]))
                {
                    val = (val * 10) + (exp[i]-'0');
                    i++;
                }
                value.push(val);
                i--;
            }

            else if(exp[i]==')')
            {
                while(!optr.empty() && optr.top() != '(')
                {
                    int val2 = value.top();
                    value.pop();

                    int val1 = value.top();
                    value.pop();
                    
                    char op = optr.top();
                    optr.pop();
                    
                    value.push(applyOperation(val1, val2, op));
                }
                if(!optr.empty())
                    optr.pop();
            }
            else
            {
                while(!optr.empty() && getPrecedence(optr.top()) >= getPrecedence(exp[i]))
                {
                    int val2 = value.top();
                    value.pop();
                    
                    int val1 = value.top();
                    value.pop();
                    
                    char op = optr.top();
                    optr.pop();
                
                    value.push(applyOperation(val1, val2, op));
                }
                optr.push(exp[i]);
            }
        }

        while(!optr.empty())
        {
            int val2 = value.top();
            value.pop();
                     
            int val1 = value.top();
            value.pop();
                     
            char op = optr.top();
            optr.pop();
                
            value.push(applyOperation(val1, val2, op));
        }
        return value.top();
    }
}