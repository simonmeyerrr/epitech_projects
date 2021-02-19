#ifndef JSONERROR_HPP_
#define JSONERROR_HPP_

#define error(MSG)throw std::string{"Error in "} + __FILE__ + " at line " + std::to_string(__LINE__) + " :: " + MSG;
#define certify(B, MSG)if (!(B)){error("certify failed :: " + MSG);}

#endif
