#include <iostream>
#include <cmath>

using namespace std;

int main() {

//    masa w mg
    float G;
//    Udział zuzla
    float b1;
    cout<<"Podaj masę ciekłej stali w mg: "<<endl;
    cin>>G;
    cout<<"Podaj udział zuzla w stosunku do masy stali w %: "<<endl;
    cin>>b1;

    float b = b1 / 100;
    float a = 0.14;
    float c = 0.325;

//    Udział dodatkowej objetosci
    float e;
    cout<<"Podaj udział dodatkowej objetosci (0.05 - 0.15)"<<endl;
    cin>>e;
//    Kąt nachylenia częsci stozkowej alfa
    float K;
    cout<<"Podaj kąt nachylenia częsci stozklowej alfa"<<endl;
    cin>>K;
//    Stosunek średnicy do głębokości
    float ks;
    cout<<"Podaj stosunek średnicy do głębokości"<<endl;
    cin>>ks;

    float V1 = a * G;
    float V2 = V1+b*c*G+e*V1;

    float Aa;

    if (G <= 20) {
        Aa = 0.31;
    }
    if (G > 20 && G <= 50) {
        Aa = 0.32;
    }
    if (G > 50 && G <= 100) {
        Aa = 0.33;
    }
    if (G > 100) {
        Aa = 0.345;
    }

    float HA = Aa * pow(G, 0.25);
    float HB = pow((float(3000) * V2 / (3.14 * (float(675) * pow(ks, float(2)) - float(1200) * ks * (float(1) / tan(K * 3.14 / float(180))) + float(704) * pow((float(1) / tan(K * 3.14 / float(180))), float(2)+float(4))))), float(1)/float(3));
    cout<<"Głębokość kąpieli metalowej obliczona teoretycznie: "<<ceil(HB * 100.0) / 100.0<<endl;
    cout<<"Głębokość kąpieli metalowej obliczona empirycznie: "<<ceil(HA * 100.0) / 100.0<<endl;

    float H;
    cout<<"Jaką wielkość głębokości przyjmujesz "<<endl;;
    cin>>H;

    float h10 = 0.2 * H;
    float h2 = 0.8 * H;
    float Ba;
    if (G < 20) {
        Ba = 0.145;
    }
    if (G >= 20) {
        Ba = 0.125;
    }

    float h3 = Ba * H;
    float H1 = 0.75 * pow(G, 0.25);
    float d2A = ks * H;
    float d2B = 0.89 * H + sqrt(V2 / (0.71 * H) - pow(H, float(2) / float(4)));

    cout<<"Srednica kapieli na poziomie progu obliczona teoretycznie "<<ceil(d2B * 100.0) / 100.0<<endl;;
    cout<<"Srednica kapieli na poziomie progu obliczona empirycznie "<<d2A<<endl;;

    float d2;
    cout<<"Jaką wielkość średnicy przyjmujesz "<<endl;
    cin>>d2;
    float kso = d2 / H;
    cout<<"Obliczony z przyjętych danych współczynnik k wynosi: "<<kso;

    float d3 = d2 - 1.6 * H * (1 / tan(K * 3.14 / 180));
    float d10 = d2 + 2 * h3 * (1 / tan(K * 3.14 / 180));
    float Ca;

    if (G < 20) {
        Ca = 0.075;
    }
    if (G >= 20) {
        Ca = 0.065;
    }

    float D1 = d10 + 2 * Ca * (0.75 * pow(G, 0.25 - h3));
    float mo;

    if (G <= 2) {
        mo = 0.23;
    }
    if (G > 2 && G <= 10) {
        mo = 0.30;
    }
    if (G > 10 && G <= 40) {
        mo = 0.35;
    }
    if (G > 40) {
        mo = 0.4;
    }

    float Eo = 0.075 + mo;
    float D = d10 + 2 * Eo;
    float PP, PR;

    if (G < 25) {
        PP = 0.16 * pow(G, 0.042);
    }
    if (G >= 25) {
        PP = 0.88 * pow(G, 0.225);
    }
    if (G < 10) {
        PR = 0.133 * pow(G, 0.3);
    }
    if (G >= 10) {
        PR = 0.102 * pow(G, 0.379);
    }

    float P = PP + PR + 0.15;
    float h4 = 0.11 * D1;
    float t;

    if (G < 15) {
        t = 0.33;
    }
    if (G >= 15 && G < 40) {
        t = 0.28;
    }
    if (G > 40) {
        t = 0.23;
    }

    float M = t * d10;
    float N = 0.65 * M;
    float DN = 0.135 * M;
    float gs1 = 0.149 * pow(G, 0.174);
    cout<<"Projektowany piec o pojemności "<<G<< " mg przy założeniach: "<<endl;

//    teraz wyświetlenie
    cout<<"- Kąt nachylenia części stożkowej "<<K<<" stopni"<<endl;
    cout<<"- Udział objętości rezerwowej "<<e<<endl;
    cout<<"- Stosunek średnicy na poziomie progu do głębokości k "<<ceil(kso * 100.0) / 100.0<<endl;
    cout<<"POSIADA NASTĘPUJĄCE WYMIARY GEOMETRYCZNE: "<<endl;
    cout<<"głębokość misy: H = "<<H<<" [m]"<<endl;
    cout<<"głębokość części sferycznej: h1 = "<<h10<<" [m]"<<endl;
    cout<<"głębokość części stożkowej: h2 = "<<h2<<" [m]"<<endl;
    cout<<"dodatkowa wysokość misy nad pozioom progu okna roboczego: h3 = "<<h3<<" [m]"<<endl;
    cout<<"wysokość przestrzeni roboczej: H1 = "<<ceil(H1 * 100.0) / 100.0<<" [m]"<<endl;
    cout<<"grubość trzonu P = "<<ceil(P * 100.0) / 100.0<<" [m]"<<endl;
    cout<<"grubość sklepienia Q = "<<ceil(gs1 * 100.0) / 100.0<<" [m]"<<endl;
    cout<<"strzałka sklepienia h4 = "<<ceil(h4 * 100.0) / 100.0<<" [m]"<<endl;
    cout<<"średnica przestrzeni roboczej na styku ściany d1 = "<<ceil(d10 * 100.0) / 100.0<<" [m]"<<endl;
    cout<<"średnica części stożkowej na poziomie progu okna: d2 = "<<d2<<" [m]"<<endl;
    cout<<"średnica części sferycznej misy d3 = "<<ceil(d3 * 100.0) / 100.0<<" [m]"<<endl;
    cout<<"średnica wewnętrzna przestrzeni roboczej na wysokości sklepienia D1 = "<<ceil(D1 * 100.0) / 100.0<<" [m]"<<endl;
    cout<<"średnica wewnętrzna pancerza D = "<<ceil(D * 100.0) / 100.0<<" [m]"<<endl;
    cout<<"szerokość okna roboczego M = "<<ceil(M * 100.0) / 100.0<<" [m]"<<endl;
    cout<<"wysokość okna roboczego N = "<<ceil(N * 100.0) / 100.0<<" [m]"<<endl;
    cout<<"strzałka sklepienia rooboczego dN = "<<ceil(DN * 100.0) / 100.0<<" [m]"<<endl;
}
