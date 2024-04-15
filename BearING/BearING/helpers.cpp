#include <string>

//Defining is_vowel - Function that determines if a char is a vowel or now
bool is_vowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    else
        return false;
}

//Defining is_consonant - Function that determines if a char is a consonant or now
bool is_consonant(char c)
{
    if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
        return true;
    else
        return false;
}

//Defining end_with_double_consonant - Function that determines if a string ends with double consonant
bool ends_with_double_consonant(std::string str) {
    if (size(str) < 2)
        return false;
    else if (((is_consonant(str[size(str) - 1])) && (is_consonant(str[size(str) - 2]))) && (str[size(str) - 1] == str[size(str) - 2]))
        return true;
    else
        return false;
}

//Defining ends_with_cvc - Function that determines if a string's last 3 chars are consonant, vowel and then a  consonant
bool ends_with_cvc(std::string str) {
    if ((is_consonant(str[size(str) - 1])) && (is_vowel(str[size(str) - 2])) && (is_consonant(str[size(str) - 3])))
        return true;
    else
        return false;
}

//Defining contains_vowel - Function that determines if input string contains a vowel
bool contains_vowel(std::string input_string)

{
    for (int i = 0; i < input_string.length(); i++)
    {
        if (is_vowel(input_string[i]))
        {
            return true;
        }
    }
    return false;
}

// count_consonant_at_front - Function that counts the number of consecutive consonant
int count_consonants_at_front(std::string input_string)
{
    int count = 0;
    for (int i = 0; i < input_string.length(); i++)
    {
        if (is_vowel(input_string[i]))
        {
            break;
        }
        count++;
    }
    return count;
}

//Defining count_vowels_at_back - Function that counts the number of consecutive vowels in input string
int count_vowels_at_back(std::string input_string)
{
    int count = 0;
    for (int i = input_string.length() - 1; i >= 0; i--)
    {
        if (!is_vowel(input_string[i]))
        {
            break;
        }
        count++;
    }
    return count;
}

//Defining ends_with - Function that determines whether the input(candidate) ends with a suffix
bool ends_with(std::string candidate, std::string suffix)

{
    if (candidate.length() < suffix.length())
    {
        return false;
    }
    for (int i = 0; i < suffix.length(); i++)
    {
        if (candidate[candidate.length() - suffix.length() + i] != suffix[i])
        {
            return false;
        }
    }
    return true;
}

/*Defining new_ending -- Function that creates a new string with contents same as _candidate_ but removes specified chars
 *from suffix and replaces with a replacement
 */
std::string new_ending(std::string candidate, int suffix_length, std::string replacement)
{
    if (candidate.length() < suffix_length)
    {
        return candidate;
    }
    return candidate.substr(0, candidate.length() - suffix_length) + replacement;
}