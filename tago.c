#include<stdio.h>//printf関数のために宣言
#include<stdlib.h>//malloc関数を使用するため宣言
#include<time.h>

//変数numは全ての関数で使用するのでグローバル変数とする
int num=0;

//関数を使用するためのプロトタイプ宣言
void judgement(int hands[num]);

int main(void){
    //変数nは人数
    int i=0,n=3;

    //人数の設定
    num=n;

    // 乱数の偏りをなくすため
    srand(time(0));
    //人数ぶんの手を設定
    int hand;
    int hands[3];
    for(int i=0;i<3;i++){
    hand = (rand() % 3);
    hands[i]=hand;
    }
    i=0;
    //じゃんけんの出す手を設定する
    while(i<num){
      while(hands[i]!=0 && hands[i]!=1 && hands[i]!=2){
            scanf("%d",&hands[i]);
          }
        i++;
    }
    //勝敗を判定する関数を動かす
    judgement(hands);
    return 0;
}

//勝敗の判定する関数
void judgement(int hands[num]){
    int rock=0,sizzor=0,paper=0;
    int n;
    //じゃんけんの出した手の個数を格納する
    for(int i=0;i<num;i++){
        if(hands[i]==0){
            rock++;
        }
        else if(hands[i]==1){
            sizzor++;
        }
        else if(hands[i]==2){
            paper++;
        }

    }

    /*for(int i = 0 ; i <3; i++){
      printf("%d",hands[i]);
      }
      printf("------------¥n");*/


    //グー、チョキ、パーのすべての手が出るか、全員が同じ手を出せば、あいこと判定する
    if((rock>0 && sizzor>0 && paper>0) || (rock==num || sizzor==num || paper==num)){
        printf("あいこです\n");
    }

    //グー、チョキのみの場合の判定
    else if(rock==0){
        for(int i=0;i<num;i++){
            if(hands[i]==1){
                if(n>0){
                    printf("%d",i+1);
                }
                n++;
            }
        }
        printf("の勝ちです！\n");
    }

    //チョキ、パーを出した場合の判定
    else if(sizzor==0){
        for(int i=0;i<num;i++){
            if(hands[i]==2){
                if(n>0){
                    printf("%d",i+1);
                }
                n++;
            }
        }
        printf("の勝ちです！\n");
    }

    //グー、パーを出した場合の判定
    else if(paper==0){
        for(int i=0;i<num;i++){
            if(hands[i]==0){
                if(n>0){
                    printf("%d",i+1);
                }
                n++;
            }
        }
        printf("の勝ちです！\n");
    }
}
