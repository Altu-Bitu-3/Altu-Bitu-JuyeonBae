#include<iostream> //입출력 헤더
#include<stack> // stack 헤더
#include<string> // string 헤더

using namespace std;

stack<char> removePair(string s) { //짝이 맞는 괄호쌍들을({}) 제거하는 함수
    //'{}' 쌍은 제외하고 문자열을 스택에 저장
    stack<char> st; //문자 저장하는 스택
    for (int i = 0; i < s.length(); i++) { //문자열 길이만큼 반복
        if (s[i] == '}' && !st.empty() && st.top() == '{') { //스택이 비지 않고, s[i]번째 문자가 } 이고, 스택 맨 위가 { 일 경우
            st.pop(); //pop 해준다.
        } else { //아닐 경우
            st.push(s[i]); //스택에 push
        }
    }

    return st; //스택 리턴
}

int countChange(stack<char> st) { //괄호를 바꾸는 최소 연산의 수를 구하는 함수
    int count = 0; //최소 연산의 수

    //스택이 빌 때 까지 연산 횟수 계산
    while (!st.empty()) { //스택이 비어 있지 않으면 반복
        //스택의 맨 위 문자 2개
        char a = st.top(); //스택 맨 위 문자 a에 저장
        st.pop(); // 삭제
        char b = st.top(); // 스택 맨 위 문자 b에 저장
        st.pop(); // 삭제

        if (a == b) { //'{{' or '}}'이면 괄호를 1번만 바꾼다
            count++; // 카운트 1추가
        }
        else { //'}{' 이면 2번 바꾼다
            count += 2; //카운트 2추가
        }
    }

    return count; //카운트 리턴
}

int main() {
    string s; //문자열 입력받을 변수
    int num = 0; //테스트 케이스 번호

    while (cin >> s) { //입력
        if (s[0] == '-') { //종료조건: '-'가 입력되면 종료
            break;
        }

        //연산
        stack<char> st = removePair(s); //괄호 짝이 맞는 쌍을 제거한 문자열을 st 저장
        int ans = countChange(st); // 괄호를 바꾸는 최소 연산을  ans 저장

        //출력
        cout << ++num << ". " << ans << '\n'; // 값 출력

    }

    return 0; //종료 
}