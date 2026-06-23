#include<string>

class Error{
    private:
    std::string errorName,errorDetail;
    public:
    Error(std::string errorName,std::string& detail);
    std::string to_string();
};