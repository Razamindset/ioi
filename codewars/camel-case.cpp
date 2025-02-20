#include <iostream>
#include <string>

std::string to_camel_case(std::string text) {
  while (true) {
    int positionUnderScore = text.find("_");
    int positionDash = text.find("-");

    if (positionUnderScore == std::string::npos &&
        positionDash == std::string::npos) {
      break;
    }

    // Get the frist separator can be underscore or dash
    int pos;
    if (positionUnderScore == std::string::npos)
      pos = positionDash;
    else if (positionDash == std::string::npos)
      pos = positionUnderScore;
    else
      pos = std::min(positionUnderScore, positionDash);

    if (pos + 1 > text.size()) break;

    char replacementChar = std::toupper(text[pos + 1]);

    text.replace(pos, 2, std::string(1, replacementChar));
  }

  return text;
}
