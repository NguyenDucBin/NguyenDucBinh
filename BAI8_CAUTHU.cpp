#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CauThu {
public:
    int maCauThu;
    string hoTen;
    string diaChi;
    string soDienThoai;
    float mucLuong;

    CauThu(int ma, const string& ten, const string& diaChi, const string& sdt, float luong)
        : maCauThu(ma), hoTen(ten), diaChi(diaChi), soDienThoai(sdt), mucLuong(luong) {}

    CauThu() : maCauThu(0), hoTen(""), diaChi(""), soDienThoai(""), mucLuong(0.0) {}

    void nhapThongTin() {
        cout << "Nhap thong tin cho cau thu:" << endl;
        cout << "Ma Cau Thu: ";
        cin >> maCauThu;
        cout << "Ho Ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Dia Chi: ";
        getline(cin, diaChi);
        cout << "So Dien Thoai: ";
        getline(cin, soDienThoai);
        cout << "Muc Luong: ";
        cin >> mucLuong;
    }

    void inThongTin() const {
        cout << "Ma: " << maCauThu << ", Ho Ten: " << hoTen << ", Dia Chi: " << diaChi
             << ", So Dien Thoai: " << soDienThoai << ", Muc Luong: " << mucLuong << endl;
    }

    float tinhTienThuong() const {
        return 0.1 * mucLuong; // Tính tiền thưởng: 10% mức lương
    }

    int getMaCauThu() const {
        return maCauThu;
    }

    string getHoTen() const {
        return hoTen;
    }
};


class ViTriThiDau {
public:
    int maViTri;
    string tenViTri;
    float mucThuong;

    ViTriThiDau() : maViTri(0), tenViTri(""), mucThuong(0.0) {}  // Thêm hàm tạo không có tham số

    ViTriThiDau(int ma, const string& ten, float thu) : maViTri(ma), tenViTri(ten), mucThuong(thu) {}

    void nhapThongTin() {
        cout << "Nhap thong tin cho vi tri thi dau:" << endl;
        cout << "Ma Vi Tri: ";
        cin >> maViTri;
        cout << "Ten Vi Tri: ";
        cin.ignore();
        getline(cin, tenViTri);
        cout << "Muc Thuong: ";
        cin >> mucThuong;
    }

    void inThongTin() const {
        cout << "Ma: " << maViTri << ", Ten Vi Tri: " << tenViTri << ", Muc Thuong: " << mucThuong << endl;
    }

    float getMucThuong() const {
        return mucThuong;
    }

    string getTenViTri() const {
        return tenViTri;
    }

};


class BangPhanCong {
public:
    CauThu* cauThu;
    ViTriThiDau* viTri;
    int soTran;

    BangPhanCong() : cauThu(nullptr), viTri(nullptr), soTran(0) {}  // Thêm hàm tạo không có tham số

    BangPhanCong(CauThu* ct, ViTriThiDau* vt, int st) : cauThu(ct), viTri(vt), soTran(st) {}

    void nhapThongTin(const vector<CauThu>& danhSachCauThu, const vector<ViTriThiDau>& danhSachViTri) {
        cout << "Nhap thong tin cho phan cong:" << endl;
        cout << "Chon Cau Thu (Ma Cau Thu): ";
        int maCauThu;
        cin >> maCauThu;
        cauThu = const_cast<CauThu*>(&danhSachCauThu[maCauThu - 1]);
        cout << "Chon Vi Tri (Ma Vi Tri): ";
        int maViTri;
        cin >> maViTri;
        viTri = const_cast<ViTriThiDau*>(&danhSachViTri[maViTri - 1]);
        cout << "Nhap so tran: ";
        cin >> soTran;
    }

    void inThongTin() const {
        cout << "Ho Ten: " << cauThu->hoTen << ", Ten Vi Tri: " << viTri->getTenViTri()
             << ", So Tran: " << soTran << endl;
    }

    int getMaCauThu() const {
        return cauThu->maCauThu;
    }

    float tinhTienThuong() const {
        return cauThu->tinhTienThuong() * soTran * viTri->getMucThuong();
    }

    void inDanhSachTienThuong() const {
        cout << "Ma Cau Thu: " << cauThu->maCauThu << ", Ho Ten: " << cauThu->hoTen
             << ", Tong Tien Thuong: " << tinhTienThuong() << endl;
    }
};

bool soSanhTheoHoTen(const BangPhanCong& a, const BangPhanCong& b) {
    return a.cauThu->hoTen < b.cauThu->hoTen;
}

bool soSanhTheoSoTran(const BangPhanCong& a, const BangPhanCong& b) {
    return a.soTran > b.soTran;
}

float tongTienThuong(int maCauThu, vector<BangPhanCong>& danhSachPhanCong) {
    float tongThuong = 0.0;
    for (const auto& phanCong : danhSachPhanCong) {
        if(maCauThu == phanCong.getMaCauThu()) {
            tongThuong += phanCong.tinhTienThuong();
        }
    }
    return tongThuong;
}

int main(int argc, char* argv[] ) {
    vector<CauThu> danhSachCauThu;
    vector<ViTriThiDau> danhSachViTri;
    vector<BangPhanCong> danhSachPhanCong;

    int soLuongCauThu, soLuongViTri, soLuongPhanCong;

    cout << "Nhap so luong cau thu: ";
    cin >> soLuongCauThu;

    for (int i = 0; i < soLuongCauThu; ++i) {
        CauThu cauThuTemp;
        cauThuTemp.nhapThongTin();
        danhSachCauThu.push_back(cauThuTemp);
    }

    cout << "\nDanh sach cau thu:" << endl;
    for (const auto& cauThu : danhSachCauThu) {
        cauThu.inThongTin();
    }

    cout << "\nNhap so luong vi tri thi dau: ";
    cin >> soLuongViTri;

    for (int i = 0; i < soLuongViTri; ++i) {
        ViTriThiDau viTriTemp;
        viTriTemp.nhapThongTin();
        danhSachViTri.push_back(viTriTemp);
    }

    cout << "\nDanh sach vi tri thi dau:" << endl;
    for (const auto& viTri : danhSachViTri) {
        viTri.inThongTin();
    }

    cout << "\nNhap so luong phan cong: ";
    cin >> soLuongPhanCong;

    for (int i = 0; i < soLuongPhanCong; ++i) {
        BangPhanCong phanCongTemp;
        phanCongTemp.nhapThongTin(danhSachCauThu, danhSachViTri);
        danhSachPhanCong.push_back(phanCongTemp);
    }

    cout << "\nDanh sach phan cong:" << endl;
    for (const auto& phanCong : danhSachPhanCong) {
        phanCong.inThongTin();
    }

    sort(danhSachPhanCong.begin(), danhSachPhanCong.end(), soSanhTheoHoTen);

    cout << "\nDanh sach phan cong sau khi sap xep theo Ho Ten:" << endl;
    for (const auto& phanCong : danhSachPhanCong) {
        phanCong.inThongTin();
    }

    sort(danhSachPhanCong.begin(), danhSachPhanCong.end(), soSanhTheoSoTran);

    cout << "\nDanh sach phan cong sau khi sap xep theo So Tran:" << endl;
    for (const auto& phanCong : danhSachPhanCong) {
        phanCong.inThongTin();
    }

    cout << "\nDanh sach tien thuong cua cac cau thu:" << endl;
    for (const auto& cauThu : danhSachCauThu) {
        cout << "Ma cau thu: " << cauThu.getMaCauThu() << ", Ten cau thu: " << cauThu.getHoTen() << ", Muc thuong: " << tongTienThuong(cauThu.getMaCauThu(), danhSachPhanCong) << endl;
    }


    return 0;
}

