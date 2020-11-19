// algorithm.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL < 60;//十分大きな値で初期化


//全探索(bit探索)
//部分和問題
bool bit(int N,int W,const vector<int> &a) {
    bool exist = false;
    for (int bit = 0; bit < (1 << N); ++bit) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                sum += a[i];
            }
        }

        if (sum == W) exist = true;
    }

    return exist;
}

//再帰関数
//部分和問題
bool func(int N, int W, const vector<int>& a) {

    //ベースケース
    if (N == 0) {
        if (W == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    //選ぶ時
    if (func(N - 1, W - a[N - 1], a)) return true;

    //選ばない時
    if (func(N - 1, W, a)) return true;

    //どちらもfalseの場合はfalseを返す
    return false;
}

//動的計画法
//Frog問題
long long  func2(int N, const vector<int>& a) {
    vector<long long> dp(N,INF); //dp配列を十分大きな値で初期化

    //初期条件
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        if (i == 1) {
            dp[i] = abs(a[i] - a[i - 1]);
        }
        else {
            dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
        }
    }

    return dp[N - 1];
}

//動的計画法(緩和)
//Frog問題
template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}


int main()
{
    int N;
    cin >> N;
    vector<int> h(N);

    for (int i = 0; i < N; i++) cin >> h[i];

    vector<long long> dp(N, INF); //dp配列を十分大きな値で初期化
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));

        if (i > 1) {
            chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }

    cout << "ゴールまでの最短コストは以下である" << endl;
    cout << "最短コスト:" << dp[N - 1] << endl;

    /*if (func(N, W, a)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }*/
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
