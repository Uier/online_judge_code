class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 )    return false;
        int tmp = x, y = 0;
        while ( tmp ) {
            y = y*10+tmp%10;
            tmp /= 10;
        }
        if ( x == y )   return true;
        else    return false;
    }
};
