string getpalindrome(string s, int r1, int r2)
{
    while (r1  >= 0 && r2  <= s.size() - 1 && s[r1] == s[r2 ])
    {
        r1--;
        r2++;
    }
    return s.substr(r1 + 1, r2 - r1 - 1);
}

string lps(string s)
{
    string longest = "";
    for (int i = 0; i < s.size(); i++)
    {
        string palin = getpalindrome(s, i, i);
        if (palin.size() > longest.size())
        {
            longest = palin;
        }
    }

    for (int i = 0; i < s.size() -1; i++)
    {
        string palin = getpalindrome(s, i, i+1);
        if (palin.size() > longest.size())
        {
            longest = palin;
        }
    }

    return longest;
}

int main()
{
    //Input: s = "babad"
    //Output : "bab"
    string s = "babad";
    string longest = lps(s);
    cout << "longest palindrome: " << longest.c_str() << endl;

}
