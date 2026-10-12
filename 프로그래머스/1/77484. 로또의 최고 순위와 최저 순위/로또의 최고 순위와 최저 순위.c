#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2);
    
    int i = 0, j = 0, best_cnt = 0, worst_cnt = 0;
    
    for(i = 0; i < lottos_len; i++)
    {
        if(lottos[i] == 0)
            best_cnt++;
        
        else
        {
            for(j = 0; j < win_nums_len; j++)
            {
                if(lottos[i] == win_nums[j])
                {
                    best_cnt++; worst_cnt++;
                    break;
                }
            }
        }
    }
    
    for(i = 2; i <= 6; i++)
    {
        if(best_cnt == 0 || best_cnt == 1)
        {
            answer[0] = 6;
            break;
        }
        
        else if (best_cnt == i)
        {
            answer[0] = 6 - i + 1;
            break;
        }
    }
    
    for(i = 2; i <= 6; i++)
    {
        if(worst_cnt == 0 || worst_cnt == 1)
        {
            answer[1] = 6;
            break;            
        }
        
        else if (worst_cnt == i)
        {
            answer[1] = 6 - i + 1;
            break;
        }
    }
    
    return answer;
}