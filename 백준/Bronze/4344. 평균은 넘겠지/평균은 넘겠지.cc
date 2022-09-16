#include <stdio.h>

int main()
{
    int caseNum;
    scanf("%d", &caseNum);
    
    int studentNum;
    float scoreAvg;
    float ratio[caseNum];
    
    for(int i = 0; i < caseNum; ++i)
    {
        scanf("%d", &studentNum);
        int score[studentNum];
        
        int scoreSum = 0;
        for(int j = 0; j < studentNum; ++j)
        {
            scanf("%d", &score[j]);
            scoreSum += score[j];
        }
        scoreAvg = scoreSum / (float)studentNum;
        
        int smartNum = 0;
        for(int j = 0; j < studentNum; ++j)
        {
            if(scoreAvg < score[j]) smartNum++;
        }
        ratio[i] = 100 * (smartNum / (float)studentNum);
    }
    for(int i = 0; i < caseNum; ++i)
    {
        printf("%.3f%%\n", ratio[i]);
    }
    
    return 0;
}