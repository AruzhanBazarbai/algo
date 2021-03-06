// /*
// 1590. Шифр Бэкона
// Ограничение времени: 2.0 секунды
// Ограничение памяти: 64 МБ
// Программисту Васе не повезло — вместо отпуска его послали в командировку, на научную конференцию. Надо повышать уровень знаний, 
// сказал начальник, важная конференция по криптографии, проводится во Франции — а там шифровали еще во времена Ришелье и взламывали чужие шифры 
// еще во времена Виета.
// Вася быстро выяснил, что все луврские картины он уже где-то видел, вид эйфелевой башни приелся ему еще раньше, чем мышка стерла его с коврика,
//  а такие стеклянные пирамиды у нас делают надо всякими киосками и сомнительными забегаловками. Одним словом, смотреть в Париже оказалось 
//  просто не на что, рыбу половить негде, поэтому Васе пришлось посещать доклады на конференции.
// Один из докладчиков, в очередной раз пытаясь разгадать шифры Бэкона, выдвинул гипотезу, что ключ к тайнам Бэкона можно подобрать, 
// проанализировав все возможные подстроки произведений Бэкона.
// «Но их же слишком много!» — вслух удивился Вася.
// «Нет, не так уж и много!» — закричал докладчик — «подсчитайте и вы сами убедитесь!».
// Тем же вечером Вася нашел в интернете полное собрание сочинений Бэкона. Он написал программу, которая переработала тексты в одну длинную 
// строку, выкинув из текстов все пробелы и знаки препинания. И вот теперь Вася весьма озадачен — а как же подсчитать количество различных 
// подстрок этой строки?
// Исходные данные
// На входе дана непустая строка, полученная Васей. Строка состоит только из строчных латинских символов. Ее длина не превосходит 5000 символов.
// Результат
// Выведите количество различных подстрок этой строки.
// */
#include <iostream>
#include <vector>
using namespace std;
// done
int prefix_f(string s){
    int n=(int)s.size(),cnt=0;
    vector<int> pi(n+1);
    for(int i=0;i<n;i++){
        pi[1]=0;
        int len=0;
        int maxi=0;
        for(int j=1;j<s.size();j++){
            while(true){
                if(s[j]==s[len]){
                    len++;
                    break;
                }
                if(len==0) break;
                len=pi[len];
            }
            pi[j+1]=len;
            maxi=max(len,maxi);
        }
        cnt+=(int)s.size()-maxi;
        s.erase(s.begin());
        
    }
    // for(int x:pi) cout << x << " ";
    // cout << endl;
    return cnt;

}
int main(){
    string s;
    int n;
    cin >> s;
    cout << prefix_f(s) << endl;
    // while(n--){
    //     cin >> s;
    //     int cnt=prefix_f(s);
    //     cout << cnt << endl;
    // }
    return 0;
}