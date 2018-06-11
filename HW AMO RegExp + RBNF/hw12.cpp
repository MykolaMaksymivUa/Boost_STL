#include <iostream>
#include <string>
#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;

template <typename Iterator>
struct calculator_simple : qi::grammar<Iterator>{
    calculator_simple() : calculator_simple::base_type(expression){
        expression = term   >> *( '+' >> term   | '-' >> term );
        term       = factor >> *( '*' >> factor | '/' >> factor );

        factor     = 
		    qi::uint_
            |  '(' >> expression >> ')'
            | '+' >> factor
            | '-' >> factor;
    }

    qi::rule<Iterator> expression, term, factor;
};


int main(){
    std::cout << "Welcome to the expression parser!\n\n";
    std::cout << "Type an expression or [q or Q] to quit\n\n";

    typedef std::string     str_t;
    typedef str_t::iterator str_t_it;

    str_t expression;

    calculator_simple<str_t_it> calc;

    while(true){
        std::getline(std::cin, expression);
        if(expression == "q" || expression == "Q") break;
        str_t_it begin = expression.begin(), end = expression.end();

        bool success = qi::parse(begin, end, calc);

        std::cout << "---------------------\n";
        if(success && begin == end)
                std::cout << "Parsing succeeded\n";
        else
                std::cout << "Parsing failed\nstopped at: \""
                          << str_t(begin, end) << "\"\n";
        std::cout << "---------------------\n";
    }
}