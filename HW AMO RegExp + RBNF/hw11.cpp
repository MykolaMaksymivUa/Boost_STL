#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <regex>

int main()
{
	std::string text =
		"Sir, in my heart there was a kind of fighting "
		"That would not let me sleep. Methought I lay "
		"Worse than the mutines in the bilboes. Rashly— "
		"And prais'd be rashness for it—let us know "
		"Our indiscretion sometimes serves us well ... "
		; // — Hamlet, Act 5, Scene 2, 4–8

	std::regex token_re("[S][a-z]+", std::regex::icase);
	std::copy(std::sregex_token_iterator(text.begin(), text.end(), token_re, 0),
		std::sregex_token_iterator(),
		std::ostream_iterator<std::string>(std::cout, "\n"));

	return 0;
}
