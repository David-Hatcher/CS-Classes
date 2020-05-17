class Calculator{
private:
    int result;
public:
    Calculator& multiply(int a, int b){
        this->result = a * b;
        return *this;
    }

    Calculator& square_result(){
        this->result *= this->result;
        return *this;
    }

    int get_result(){
        return this->result;
    }
};