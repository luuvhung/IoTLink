#include<iostream>
template<class T>
class Stack
{
    private:
        T* stack;
        int total;
        int size;
    public:
        Stack(int size)
        {
            this->size = size;
            stack = new T[size];
            total = 0;
        }
        ~Stack()
        {
            delete[] stack;
        }
        bool isEmpty()
        {
            if (total == 0) return true;
            else return false;
        }
        bool isFull()
        {
            if (total == size) return true;
            else return false;
        }
        bool push(T obj)
        {
            if (isFull()==false)
            {
                stack[total] = obj;
                total++;
                return true;
            }
            else return false;
        }
        T pop()
        {
            if (isEmpty()==false)
            {
                T obj = stack[total - 1];
                stack[total - 1]= NULL;
                total--;
                return obj;
            }
            else return NULL;
        }
        T getItem(int i)
        {
            return stack[i-1];
        }
        int getTotal()
        {
            return total;
        }
};
int main()
{
    Stack<int> st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    st.pop();
    system("pause");
}