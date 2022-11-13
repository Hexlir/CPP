//
// Created by el on 26/10/2022.
//

/* Djowen sangat menyukai kegiatan memanggang dan menghias kue. Untuk menyalurkan hobinya, ia pun membuka toko kue.

Di toko kue tersebut terdapat NN buah meja yang dinomori dari 11 hingga NN. Awalnya, semua meja kosong dan ia akan menggunakan meja-meja tersebut untuk membuat kue. Setiap kue yang ia ingin buat memiliki cara preparasi yang berbeda-beda. Maka dari itu, Djowen akan melakukan semua aksi sesuai dengan urutan yang tertera pada daftar AA. Terdapat MM aksi pada AA, dinomori dari 1 hingga MM. Pada urutan ii, ia akan melakukan aksi berikut terhadap meja A_iA*/

#include "bits/stdc++.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long N,M;

    cin >> N >> M;

    vector<long> A;

    for(long i = 0; i < M; i++){

        long temp;
        cin >> temp;
        A.push_back(temp);
    }

    vector<long> B;
    for(long i = 0; i < N; i++){
        B.push_back(0);
    }

    for(long i = 0; i < M; i++){
        B[A[i]-1] = 1;
    }

    for(long i = 0; i < N; i++){
        if(B[i] == 0){
            cout << i+1 << endl;
        }
        cout << B[i] << endl;
    }


    return 0;
}