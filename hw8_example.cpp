#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>
#include <string>
using boost::lexical_cast;
using boost::bad_lexical_cast;
#define NEW_INPUT 0
#define NEW_VENDOR 1
#define NEW_CONSUMER 2
int main (int argc, char * argv []) {
    unsigned int selector = NEW_INPUT;
    std::vector<short> vendorId;
    std::vector<short> consumerId;	
    
	while (*++argv ) {
	    switch (selector){
		    case NEW_INPUT:		
	            try{
                    lexical_cast<std::string>(*argv) == "vendorId" 
					    ? selector = NEW_VENDOR 
						: 0;
					lexical_cast<std::string>(*argv) == "consumerId" 
					    ? selector = NEW_CONSUMER
						: 0;
		        }
                catch (const bad_lexical_cast &) {
	                //...
	            }
				break;
		    case NEW_VENDOR:		
	            try{
				    selector = NEW_INPUT;
                    vendorId.push_back(lexical_cast<short>(*argv));
		        }
                catch (const bad_lexical_cast &) {
	                vendorId.push_back(0);
	            }
				break;
		    case NEW_CONSUMER:		
	            try{
				    selector = NEW_INPUT;				
                    consumerId.push_back(lexical_cast<short>(*argv));
		        }
                catch (const bad_lexical_cast &) {
	                consumerId.push_back(0);
	            }
				break;				
		}
    }
	std::cout << "vendorId count = " << vendorId.size() << std::endl;
	std::cout << "consumerId count = " << consumerId.size() << std::endl;
}