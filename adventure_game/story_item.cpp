#include "story_item.h"
#include "utils.h"

using namespace std;


string preText = "";
string preTextColour = "";
string prompt = "";
vector<string> options;

int StoryItem::run() {
    if (this->preText.length() > 0) {
        printInColor(this->preText, this->preTextColour);
    }
    if (this->prompt.length() > 0) {
        printInColor(this->prompt, "blue");
    }

    int count = 1;
    for (auto i = this->options.begin(); i != this->options.end(); ++i) {
        printInColor(to_string(count) + ") " + *i);
        count += 1;
    }

    // return 0;
    return int_option(this->options.size());
}