#include "Tetris.hpp"


int main()
{
    int i, a,sonuc;
    srand(time(0));
    vector<vector<char>> temps;
	vector<vector<char>> testVect(2, vector<char>(2, '*'));
    vector<vector<char>> testVect2(30, vector<char>(30, '*'));
    vector<vector<char>> testVect3(5, vector<char>(5, '*'));


    Tetromino dene(block_type::Z);
    Tetromino dene2(block_type::O);
    Tetris dene1(5, 5);
   // ---------------------------Rotate and print of Tetromino class -------------------------- 
    cout << "Rotate func: \n\n";
    dene.print();
    cout << endl << "Rotated : \n\n";
    dene.rotate('+');
    dene.print();
    cout << endl <<"--------------------------------" << endl;
    //------------------------------------ getShapeOfTetris() function -------------------
    cout << "Getshape function: \n";
    for(i=0; i<dene.getShapeOfTetris().size(); i++)
    {
        for(int j=0; j<dene.getShapeOfTetris()[i].size(); j++)
            cout << dene.getShapeOfTetris()[i][j];
        cout << endl;
    }
    cout << endl <<"--------------------------------" << endl;
    //------------------------------------ Gettype function --------------------------------
    cout << "Gettype function: \n";
    cout << dene.get_type()<<endl;
    cout << endl <<"--------------------------------" << endl;

    //------------------------------------ Draw function ---------------------------------------
    cout << "Draw func: \n";
    dene1.draw();
    cout << endl <<"--------------------------------" << endl;
    //------------------------------------ Get row and clmn func ----------------------------
    cout << endl << "Get row and clmn func:\nBoyutları: \n";
    cout << dene1.GetLenOfClmn() << " "<< dene1.GetLenOfRow() << endl ;
    cout << endl <<"--------------------------------" << endl;
    //------------------------------------ setter -----------------------------
    cout << "Setter fonksiyonum: \nNo parameter olarak boş olan vektör: \n";
    Tetromino dene3;

    dene3.print();
    cout << endl;
    dene3.setter(block_type::I);
    cout << "Setter ile güncellenen hali: \n";
    dene3.print();
    cout << endl <<"--------------------------------" << endl;

    //------------------------------------ Fit func -----------------------------
    cout << "Devam etmek için bir sayı giriniz: ";
    cin >> a;
    cout << "For fit func: \nöncesi: \n\n";

    cout << "Bekleyin hocam geliyo: \n";
    dene1.draw();
    sleep(3);
    cout << endl;
    cout<<"sonrası: \n";
    dene1.Fit(dene, '-');
    cout << endl <<"--------------------------------" << endl;
    
    //------------------------------------ get tetro obj func -------------------------
    cout << "\nTetromino &get_Tetro_Obj(){return ( tetro_obj);} fonk : \n";
    dene1.get_Tetro_Obj().print();
    cout << endl <<"--------------------------------" << endl;
   //------------------------------------ isvalid func ---------------------------- 
    sonuc=dene1.isvalid_place(testVect, dene, 2, 0);
    cout << "ikiye iki vektör olduğu için -1 döndürmeli. Sonuç: " << sonuc << endl;
    sonuc=dene1.isvalid_place(testVect2, dene, 10, 10);
    cout << "Boş vektör olduğu için 1 döndürmeli. Sonuç: " << sonuc << endl;
    cout << endl <<"--------------------------------" << endl;

    //cout << "Devam etmek için bir sayı giriniz: ";
    //cin >> i;
    cout << "Boardda Z'nin yanına o geldiğinde kalan boşluk: \n";
    dene1.draw();
    cout << "Bekleyin hocam yeni hali geliyor\n";
    sleep(5);
    
    dene1.Fit(dene2, '-');
    for(i=0; i<dene1.getBoard().size(); i++)
    {
        for(a=0; a<dene1.getBoard()[i].size(); a++)
        {
            testVect3[i][a] =dene1.getBoard()[i][a];
            //cout << testVect3[i][a];
        }
        //cout << endl;
    }
    sonuc = dene1.how_many_rotate(dene2, 3, 4, 3, testVect3);
    cout << "Görseldeki iki tetromino arasındaki boşluğu sayarsak " << sonuc << " olduğunu görürüz.\n" ;
    cout << endl <<"--------------------------------" << endl;
    //------------------------------------ Length func --------------------
    cout << "dene2 objem içinde o şeklini tutuyor. Yüksekliğin iki olmasını bekleriz.\n";
    dene2.print();
    cout << endl;
    int len;
    dene1.lenght_of_object(len, dene2);
    cout << "Objenin yüksekliği: " << len <<endl;
    return 0;
}