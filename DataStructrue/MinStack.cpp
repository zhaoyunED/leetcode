Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.




//方法1 两个栈

stack<int> data;
stack<int> min;

public:

    void push(int x) {

        // If empty
        if (min.empty()) {
            data.push(x);
            min.push(x);
        }

        // Not empty
        else {
            data.push(x);
            if (x <= min.top())
                min.push(x);
        }

    }

    void pop() {

        if (!min.empty()) {
            if (data.top() == min.top())
                min.pop();
            data.pop();
        }
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }

//方法2
class MinStack {
    int min=Integer.MAX_VALUE;
    Stack<Integer> stack = new Stack<Integer>();
    public void push(int x) {
       // only push the old minimum value when the current 
       // minimum value changes after pushing the new value x
        if(x <= min){          
            stack.push(min);
            min=x;
        }
        stack.push(x);
    }

    public void pop() {
       // if pop operation could result in the changing of the current minimum value, 
       // pop twice and change the current minimum value to the last minimum value.
        if(stack.peek()==min) {
            stack.pop();
            min=stack.peek();
            stack.pop();
        }else{
            stack.pop();
        }
        if(stack.empty()){
            min=Integer.MAX_VALUE;
        }
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return min;
    }
}

//方法3

public class MinStack {
    long min;
    Stack<Long> stack;

    public MinStack(){
        stack=new Stack<>();
    }

    public void push(int x) {
        if (stack.isEmpty()){
            stack.push(0L);
            min=x;
        }else{
            stack.push(x-min);//Could be negative if min value needs to change
            if (x<min) min=x;
        }
    }

    public void pop() {
        if (stack.isEmpty()) return;

        long pop=stack.pop();

        if (pop<0)  min=min-pop;//If negative, increase the min value

    }

    public int top() {
        long top=stack.peek();
        if (top>0){
            return (int)(top+min);
        }else{
           return (int)(min);
        }
    }

    public int getMin() {
        return (int)min;
    }
}