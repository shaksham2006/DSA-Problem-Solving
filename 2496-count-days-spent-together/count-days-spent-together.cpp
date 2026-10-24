class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,string arriveBob, string leaveBob) {
        // days are the days in each month given in problem
        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};
        // The convert function here changes the day and month to exact number of days in year till that day of the month
        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));         //stoi is functio of str to int
            for (int i = 0; i < month - 1; i++) {
                day += days[i];
            }
            return day;
        };
        int a1 = convert(arriveAlice);
        int a2 = convert(leaveAlice);
        int b1 = convert(arriveBob);
        int b2 = convert(leaveBob);
        int start = max(a1, b1);
        int end = min(a2, b2);                  
        // now we just have to substract the days from the exact days in year format
        return max(0, end - start + 1);
    }
};