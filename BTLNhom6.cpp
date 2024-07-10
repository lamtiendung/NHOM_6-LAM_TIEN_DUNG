#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
struct KhachHang {
    int id;
    string ten;
    string gioiTinh;
    string soDienThoai;
    float sotien;
    KhachHang* next;
    KhachHang* prev;
};

class QuanLyKhachHang {
private:
    KhachHang* head;
    KhachHang* tail;

public:
    QuanLyKhachHang();
    ~QuanLyKhachHang();
    void layDanhSachKhachHangTuFile(const string& filename);
    void xuatDanhSachKhachHang();
    void sapXepKhachHangTheoIdTangDan();
    void themKhachHangDauDanhSach();
    void themKhachHangCuoiDanhSach();
    void thayTheKhachHangViTriBatKy();
    void capNhapThongTinKhachHang(KhachHang* kh);
    void xoaKhachHangDauDanhSach();
    void capNhapID(int oldID, int newID);
    void sapXepTheoSotienGiamDan();
    void sapXepTheoSotienTangDan();
    float tinhTrungBinh();
    void hienThiKhachHangCoSoTienLonHon(float sotien);
    void ghiDanhSachKhachHangRaFile(const string& filename);
    void timKhachHangTheoTen(string ten);
    void timKhachHangTheoGioiTinh(string gioiTinh);
    float tinhTongSoTien();
    int demSoLuongKhachHang();
    void hienThiKhachHangCoSoTienNhoHon(float sotien);
    void chuyenDoiGioiTinh(int id);
    void capNhapTenKhachHang(int id, string tenMoi);
    void hienThiKhachHangTheoKhoangSoTien(float minSoTien, float maxSoTien);
    void kiemTraSoDu(int id);
    void kiemTraSoDienThoai(int id);
    void capNhapSoDienThoai(int id, string soDienThoaiMoi);
    void xoaTatCaKhachHang();

    void menu();

private:
    KhachHang* timKhachHangTheoID(int id);
};

QuanLyKhachHang::QuanLyKhachHang() {
    head = NULL;
    tail = NULL;
}

QuanLyKhachHang::~QuanLyKhachHang() {
    KhachHang* current = head;
    while (current != NULL) {
        KhachHang* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
}
void QuanLyKhachHang::layDanhSachKhachHangTuFile(const string& filename) {
    ifstream file(filename.c_str());
    if (!file) {
        cout << "Khong mo duoc file " << filename << endl;
        return;
    }

    while (!file.eof()) {
        KhachHang* kh = new KhachHang;
        file >> kh->id;
        file >> kh->ten;
        file >> kh->gioiTinh;
        file >> kh->sotien;
		file >> kh->soDienThoai;
        if (file.fail()) {
            delete kh;
            break;
        }

        kh->next = head;
        head = kh;
    }

    file.close();
}
void QuanLyKhachHang::xuatDanhSachKhachHang() {
    if (head == NULL) {
        cout << "Danh sach khach hang rong." << endl;
        return;
    }

    KhachHang* current = head;
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}
void QuanLyKhachHang::sapXepKhachHangTheoIdTangDan() {
    KhachHang *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->id > j->id) {
                swap(i, j);
            }
        }
    }
    KhachHang* current = head;
    cout << "	Danh sach khach hang sap xep theo id tang dan:" << endl;
    while (current != NULL) {
        cout << "	ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}
void QuanLyKhachHang::themKhachHangDauDanhSach() {
    KhachHang* kh = new KhachHang;
    cout << "Nhap thong tin khach hang moi vao dau danh sach:" <<endl;
    cout << "ID: ";
    cin >> kh->id;
    cout << "Ten: ";
    cin.ignore();
    getline(cin, kh->ten);
    cout << "Gioi tinh: ";
    getline(cin, kh->gioiTinh);
    cout << "So tien: ";
    cin >> kh->sotien;
    cin.ignore();
    cout << "So dien thoai: ";
    getline(cin, kh->soDienThoai);

    kh->next = head;
    kh->prev = NULL;

    if (head != NULL) {
        head->prev = kh;
    }
    	head = kh;

    if (tail == NULL) {
        tail = kh;
    }
    KhachHang* current = head;
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}
KhachHang* QuanLyKhachHang::timKhachHangTheoID(int id) {
    KhachHang* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void QuanLyKhachHang::themKhachHangCuoiDanhSach() {
    KhachHang* kh = new KhachHang;
    cout << "Nhap thong tin khach hang moi vao cuoi danh sach:" << endl;
    cout << "ID: ";
    cin >> kh->id;
    cout << "Ten: ";
    cin.ignore();
    getline(cin, kh->ten);
    cout << "Gioi tinh: ";
    getline(cin, kh->gioiTinh);
    cout << "So tien: ";
    cin >> kh->sotien;
    cin.ignore();
    cout << "So dien thoai: ";
    getline(cin, kh->soDienThoai);
    if (tail != NULL) {
    	tail->next=kh;
    }
    	tail = kh;
    if (head == NULL) {
        head = kh;
    }
	KhachHang* current = head;
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}

void QuanLyKhachHang::thayTheKhachHangViTriBatKy() {
    int pos;
    cout << "Nhap vi tri muon thay the khach hang: ";
    cin >> pos;

    if (pos < 0) {
        std::cout << "Vi tri khong hop le." <<endl;
        return;
    }

    KhachHang* kh = new KhachHang;
    cout << "Nhap thong tin khach hang moi:" <<endl;
    cout << "ID: ";
    cin >> kh->id;
    cout << "Ten: ";
    cin.ignore();
    getline(std::cin, kh->ten);
    cout << "Gioi tinh: ";
    getline(std::cin, kh->gioiTinh);
    cout << "So tien: ";
    cin >> kh->sotien;
    cin.ignore();
    cout << "So dien thoai: ";
    getline(cin, kh->soDienThoai);

    kh->next = NULL;
    kh->prev = NULL;

    if (pos == 0) {
        kh->next = head;
        if (head != NULL) {
            head->prev = kh;
        }
        head = kh;
        if (tail == NULL) {
            tail = kh;
        }
        return;
    }

    KhachHang* current = head;
    int count = 0;

    while (current != NULL && count < pos - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        cout << "Vi tri chen khong hop le." << std::endl;
        delete kh;
        return;
    }

    kh->next = current->next;
    kh->prev = current;
    if (current->next != NULL) {
        current->next->prev = kh;
    }
    current->next = kh;

    if (kh->next == NULL) {
        tail = kh;
    }
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}
void QuanLyKhachHang::capNhapThongTinKhachHang(KhachHang* kh) {
    if (kh == NULL) {
        cout << "Khong tim thay khach hang can cap nhat." << endl;
        return;
    }

    cout << "Nhap thong tin moi cho khach hang co ID " << kh->id << ":" << endl;
    cout << "Ten: ";
    cin.ignore();
    getline(cin, kh->ten);
    cout << "Gioi tinh: ";
    getline(cin, kh->gioiTinh);
    cout << "So tien: ";
    cin >> kh->sotien;
    cin.ignore();
    cout << "So dien thoai: ";
    getline(cin, kh->soDienThoai);
    KhachHang* current = head;
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
    
}

void QuanLyKhachHang::xoaKhachHangDauDanhSach() {
    if (head == NULL) {
        std::cout << "Danh sach khach hang rong." << std::endl;
        return;
    }
    KhachHang* kh = head;
    head = head->next;
    delete kh;
    if (head == NULL) {
        tail = NULL;
    }
    KhachHang* current = head;
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}
void QuanLyKhachHang::capNhapID(int oldID, int newID) {
    KhachHang* kh = timKhachHangTheoID(oldID);
    if (kh == NULL) {
        cout << "Khong tim thay khach hang co ID " << oldID << "." <<endl;
        return;
    }
    
    kh->id = newID;
    KhachHang* current = head;
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}

void QuanLyKhachHang::sapXepTheoSotienGiamDan() {
    if (head == NULL) {
        cout << "Danh sach khach hang rong." << endl;
        return;
    }

    bool swapped;
    KhachHang* ptr1;
    KhachHang* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->sotien < ptr1->next->sotien) {
                swap(ptr1->id, ptr1->next->id);
                swap(ptr1->ten, ptr1->next->ten);
                swap(ptr1->gioiTinh, ptr1->next->gioiTinh);
                swap(ptr1->sotien, ptr1->next->sotien);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    KhachHang* current = head;
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}
void QuanLyKhachHang::sapXepTheoSotienTangDan() {
    if (head == NULL) {
        cout << "Danh sach khach hang rong." << endl;
        return;
    }

    bool swapped;
    KhachHang* ptr1;
    KhachHang* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->sotien > ptr1->next->sotien) {
                swap(ptr1->id, ptr1->next->id);
                swap(ptr1->ten, ptr1->next->ten);
                swap(ptr1->gioiTinh, ptr1->next->gioiTinh);
                swap(ptr1->sotien, ptr1->next->sotien);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    KhachHang* current = head;
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}
float QuanLyKhachHang::tinhTrungBinh() {
    if (head == NULL) {
        return 0.0;
    }

    float tong = 0.0;
    int count = 0;
    KhachHang* current = head;

    while (current != NULL) {
        tong += current->sotien;
        count++;
        current = current->next;
    }

    return tong / count;
}

void QuanLyKhachHang::hienThiKhachHangCoSoTienLonHon(float sotien) {
    if (head == NULL) {
        cout << "Danh sach khach hang rong." << endl;
        return;
    }

    KhachHang* current = head;
    bool found = false;

    while (current != NULL) {
        if (current->sotien > sotien) {
            cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Khong co khach hang nao co so tien lon hon " << sotien << "." << endl;
    }
}
void QuanLyKhachHang::ghiDanhSachKhachHangRaFile(const string& filename) {
    ofstream file(filename.c_str());
    if (!file) {
        cout << "Khong mo duoc file " << filename << endl;
        return;
    }

    KhachHang* current = head;
    while (current != NULL) {
        file << current->id << " " << current->ten << " " << current->gioiTinh << " " << current->sotien <<" "<<current->soDienThoai<< endl;
        current = current->next;
    }

    file.close();
}
void QuanLyKhachHang::timKhachHangTheoTen(std::string ten) {
    KhachHang* current = head;
    bool found = false;
    while (current != NULL) {
        if (current->ten == ten) {
            cout << "ID: " << current->id <<endl;
            cout << "Ten: " << current->ten <<endl;
            cout << "Gioi tinh: " << current->gioiTinh <<endl;
            cout << "So tien: " << current->sotien <<endl;
            cout << "So dien thoai"<<current->soDienThoai<<endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Khong tim thay khach hang co ten " << ten << "." <<endl;
    }
}

void QuanLyKhachHang::timKhachHangTheoGioiTinh(string gioiTinh) {
    KhachHang* current = head;
    bool found = false;
    while (current != NULL) {
        if (current->gioiTinh == gioiTinh) {
            cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Khong tim thay khach hang co gioi tinh " << gioiTinh << "." << endl;
    }
}

float QuanLyKhachHang::tinhTongSoTien() {
    if (head == NULL) {
        return 0;
    }

    float total = 0;
    KhachHang* current = head;
    while (current != NULL) {
        total += current->sotien;
        current = current->next;
    }
    return total;
}

int QuanLyKhachHang::demSoLuongKhachHang() {
    int count = 0;
    KhachHang* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
void QuanLyKhachHang::hienThiKhachHangCoSoTienNhoHon(float sotien) {
    KhachHang* current = head;
    bool found = false;
    while (current != NULL) {
        if (current->sotien < sotien) {
            cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Khong tim thay khach hang co so tien nho hon " << sotien << "." <<endl;
    }
}

void QuanLyKhachHang::chuyenDoiGioiTinh(int id) {
    KhachHang* kh = timKhachHangTheoID(id);
    if (kh == NULL) {
        cout << "Khong tim thay khach hang co ID " << id << "." <<endl;
        return;
    }
    kh->gioiTinh = (kh->gioiTinh == "Nam") ? "Nu" : "Nam";
    KhachHang* current = head;
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}

void QuanLyKhachHang::capNhapTenKhachHang(int id, string tenMoi) {
    KhachHang* kh = timKhachHangTheoID(id);
    if (kh == NULL) {
        cout << "Khong tim thay khach hang co ID " << id << "." << endl;
        return;
    }
    kh->ten = tenMoi;
    KhachHang* current = head;
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}

void QuanLyKhachHang::hienThiKhachHangTheoKhoangSoTien(float minSoTien, float maxSoTien) {
    KhachHang* current = head;
    bool found = false;
    while (current != NULL) {
        if (current->sotien >= minSoTien && current->sotien <= maxSoTien) {
            cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Khong tim thay khach hang trong khoang so tien tu " << minSoTien << " den " << maxSoTien << "." <<endl;
    }
}

void QuanLyKhachHang::xoaTatCaKhachHang() {
    while (head != NULL) {
        KhachHang* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    std::cout << "Tat ca khach hang da bi xoa." << std::endl;
}
void QuanLyKhachHang::kiemTraSoDu(int id) {
    KhachHang* kh = timKhachHangTheoID(id);
    if (kh != NULL) {
        cout << "So du cua khach hang ID " << id << " la: " << kh->sotien <<endl;
    } else {
        cout << "Khong tim thay khach hang co ID " << id << "." <<endl;
    }
}
void QuanLyKhachHang::kiemTraSoDienThoai(int id) {
        KhachHang* kh = timKhachHangTheoID(id);
        if (kh != NULL) {
            cout << "So dien thoai cua khach hang ID " << id << " la: " << kh->soDienThoai << endl;
        } else {
            cout << "Khong tim thay khach hang co ID " << id << "." << endl;
        }
    }
void QuanLyKhachHang::capNhapSoDienThoai(int id, string soDienThoaiMoi) {
    KhachHang* kh = timKhachHangTheoID(id);
    if (kh == NULL) {
        cout << "Khong tim thay khach hang co ID " << id << "." << endl;
        return;
    }
    kh->soDienThoai = soDienThoaiMoi;
    KhachHang* current = head;
    cout << "Danh sach khach hang:" << endl;
    while (current != NULL) {
        cout << "ID: " << current->id << "		Ten: " << current->ten << "		Gioi tinh: " << current->gioiTinh << "		So tien: " << current->sotien<<"		So dien thoai: "<<current->soDienThoai << endl;
        current = current->next;
    }
}
void QuanLyKhachHang::menu() {
    int choice;
    bool exit = false;
	string filename = "danhsachkhachhang.txt";
    layDanhSachKhachHangTuFile(filename);
    while (!exit) {
        cout << "\n===== MENU =====" <<endl;
        cout << "1. Hien thi danh sach khach hang" << endl;
        cout << "2. Sap xep khach hang theo id tang dan" << endl;
        cout << "3. Them khach hang vao dau danh sach" <<endl;
        cout << "4. Them khach hang vao cuoi danh sach" << endl;
        cout << "5. Thay the khach hang vao vi tri bat ki trong danh sach" <<endl;
        cout << "6. Cap nhat thong tin khach hang theo ID" << endl;
        cout << "7. Xoa khach hang dau danh sach" <<endl;
        cout << "8. Cap nhat ID khach hang" <<endl;
        cout << "9. Sap xep danh sach khach hang theo so tien giam dan" <<endl;
        cout << "10. Sap xep danh sach khach hang theo so tien tang dan" <<endl;
        cout << "11. Tinh so tien trung binh cua danh sach khach hang" << endl;
        cout << "12. Hien thi danh sach khach hang ca so tien lon hon mot gia tri cho truoc" << endl;
        cout << "13. Xuat danh sach khach hang ra file" <<endl;
        cout << "14. Tim khach hang theo ten" <<endl;
        cout << "15. Tim khach hang theo gioi tinh" << endl;
        cout << "16. Tinh tong so tien cua tat ca khach hang" <<endl;
        cout << "17. Dem so luong khach hang" << endl;
        cout << "18. Hien thi khach hang co so tien nho hon gia tri nhap vao" << endl;
        cout << "19. Chuyen doi gioi tinh khach hang" << endl;
        cout << "20. Cap nhat ten khach hang" << endl;
        cout << "21. Hien thi khach hang trong khoang so tien" <<endl;
        cout << "22. Kiem tra so du khach hang bat ki" << endl;
        cout << "23. Kiem tra so dien thoai khach hang bat ki" << endl;
        cout << "24. Cap nhat SDT khach hang" << endl;
        cout << "25. Xoa tat ca khach hang" << endl;
        cout << "0. Thoat" <<endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        	case 1: 
				xuatDanhSachKhachHang();
                break;
            case 2:
				sapXepKhachHangTheoIdTangDan();
                break;
            case 3:
                themKhachHangDauDanhSach();
                break;
            case 4:
                themKhachHangCuoiDanhSach();
                break;
            case 5:
                thayTheKhachHangViTriBatKy();
                break;
            case 6:{
                int id;
                cout << "Nhap ID khach hang can cap nhat: ";
                cin >> id;
                KhachHang* kh = timKhachHangTheoID(id);
                capNhapThongTinKhachHang(kh);
                break;
            }
            case 7:
                xoaKhachHangDauDanhSach();
                break;
            case 8: {
                int oldID, newID;
                cout << "Nhap ID cu cua khach hang: ";
                cin >> oldID;
                cout << "Nhap ID moi cua khach hang: ";
                cin >> newID;
                capNhapID(oldID, newID);
                break;
            }
            case 9:
                sapXepTheoSotienGiamDan();
                cout << "Da sap xep danh sach khach hang theo so tien giam dan." <<endl;
                break;
            case 10:
                sapXepTheoSotienTangDan();
                cout << "Da sap xep danh sach khach hang theo so tien tang dan." <<endl;
                break;
            case 11: {
                float trungBinh = tinhTrungBinh();
                cout << "So tien trung binh cua danh sach khach hang la: " << trungBinh << endl;
                break;
            }
            case 12: {
                float sotien;
                cout << "Nhap so tien cho truoc: ";
                cin >> sotien;
                hienThiKhachHangCoSoTienLonHon(sotien);
                break;
            }
            case 13: {
                string filename;
                cout << "Nhap ten file xuat danh sach khach hang: ";
                cin >> filename;
                ghiDanhSachKhachHangRaFile(filename);
                break;
            }
             case 14: {
                string ten;
                cout << "Nhap ten khach hang can tim: ";
                cin.ignore();
                getline(std::cin, ten);
                timKhachHangTheoTen(ten);
                break;
            }
            case 15: {
                string gioiTinh;
                cout << "Nhap gioi tinh khach hang can tim (Nam/Nu): ";
                cin >> gioiTinh;
                timKhachHangTheoGioiTinh(gioiTinh);
                break;
            }
            case 16: {
                float total = tinhTongSoTien();
                cout << "Tong so tien cua tat ca khach hang: " << total <<endl;
                break;
            }
            case 17: {
                int count = demSoLuongKhachHang();
                cout << "So luong khach hang la: " << count <<endl;
                break;
            }
            case 18: {
                float sotien;
                cout << "Nhap gia tri so tien: ";
                cin >> sotien;
                hienThiKhachHangCoSoTienNhoHon(sotien);
                break;
            }
            case 19: {
                int id;
                cout << "Nhap ID khach hang can chuyen doi gioi tinh: ";
                cin >> id;
                chuyenDoiGioiTinh(id);
                break;
            }
            case 20: {
                int id;
                string tenMoi;
                cout << "Nhap ID khach hang can cap nhat ten: ";
                cin >> id;
                cout << "Nhap ten moi: ";
                cin.ignore();
                getline(std::cin, tenMoi);
                capNhapTenKhachHang(id, tenMoi);
                break;
            }
            case 21: {
                float minSoTien, maxSoTien;
                cout << "Nhap gia tri so tien thap nhat: ";
                cin >> minSoTien;
                cout << "Nhap gia tri so tien cao nhat: ";
                cin >> maxSoTien;
                hienThiKhachHangTheoKhoangSoTien(minSoTien, maxSoTien);
                break;
            }
            case 22: {
    			int id;
    			cout << "Nhap ID khach hang can kiem tra so du: ";
    			cin >> id;
    			kiemTraSoDu(id);
    			break;
			}
			case 23: {
    			int id;
    			cout << "Nhap ID khach hang can kiem tra so dien thoai: ";
    			cin >> id;
    			kiemTraSoDienThoai(id);
    			break;
    		case 24: {
                int id;
                string soDienThoaiMoi;
                cout << "Nhap ID khach hang can cap nhat SDT: ";
                cin >> id;
                cout << "Nhap SDT moi: ";
                cin.ignore();
                getline(cin, soDienThoaiMoi);
                capNhapSoDienThoai(id, soDienThoaiMoi);
                break;
                }
			case 25:
                xoaTatCaKhachHang();
                break;
            case 0:
                return;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." <<endl;
        }
    }
}
}
int main() {
    QuanLyKhachHang qlkh;
    qlkh.menu();
    return 0;
}
