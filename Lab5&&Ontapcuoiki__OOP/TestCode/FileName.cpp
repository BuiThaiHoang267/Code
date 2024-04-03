#include<iostream>
#include<vector>
using namespace std;

static int jarvan = 0;
static int reksai = 0;
static int sivir = 0;
static int illaoi = 0;
static int countjarvan = 0;
static int countreksai = 0;
static int countsivir = 0;
static int countillaoi = 0;


class General {
protected:
	string name;
	int price;
	int attack;
	int defend;
	string skill;
	string ethnicity;
	string system;
	int star;
public:
	General() {
		name = skill = ethnicity = system = '\0';
		price = attack = defend = 0;
		star = 1;
	}
	void Input() {
		cin >> attack;
		cin >> defend;
	}
	string getName() {
		return name;
	}
	void setDefend(int x) {
		defend = x;
	}
	void setAttack(int x) {
		attack = x;
	}
	int getDefend() {
		return defend;
	}
	int getAttack() {
		return attack;
	}
	int getStar() {
		return star;
	}
	void setStar(int x) {
		star = x;
	}
	virtual int Damage(int m) = 0;
};
class Jarvan : public General {
public:
	Jarvan() {
		name = "Jarvan";
		ethnicity = "Cong nghe";
		system = "Dau si";
		skill = "Thuong thuat: Sat thuong gay ra moi luot bang defend x2";
		price = 1;
	}
	int Damage(int m) {
		return m * 2 * defend;
	}
};
class Reksai : public General {
public:
	Reksai() {
		name = "Reksai";
		ethnicity = "Tien cong";
		system = "Dau si";
		skill = "Nu hoang phan no: Sat thuong gay ra moi luot thu 4 duoc x2";
		price = 2;
	}
	int Damage(int m) {
		return m * attack + m / 4 * attack;
	}
};
class Sivir : public General {
public:
	Sivir() {
		name = "Sivir";
		ethnicity = "Cong nghe";
		skill = "Guom Boomerang: Sat thuong gay ra moi luot duoc x2";
		price = 4;
	}
	int Damage(int m) {
		return m * 2 * attack;
	}
};
class Illaoi : public General {
public:
	Illaoi() {
		name = "Illaoi";
		ethnicity = "Tien cong";
		system = "Dau si";
		skill = "Loi ran khac nghiet: Sat thuong gay ra moi luot bang (attack + defend)/2";
		price = 1;
	}
	int Damage(int m) {
		return m * (attack + defend) / 2;
	}
};

class TFT {
private:
	vector<General*> G;
	int amount;
public:
	int m;
	TFT() {
		amount = m = 0;
	}
	void Input() {
		cin >> amount;
		cin >> m;
		int n = amount;
		int x;
		for (int i = 0; i <=amount; i++) {
			if (n == 0)
				break;
			cin >> x;
			G.push_back(NULL);
			if (x == 1) {
				G[i] = new Jarvan();
				G[i]->Input();
				jarvan = 1;
				countjarvan++;
				if (countjarvan % 3 == 0) {
					NangSao(G[i]->getName(), countjarvan);
					i = G.size() - 1;
				}
			}
			if (x == 2) {
				G[i] = new Reksai();
				G[i]->Input();
				reksai = 1;
				countreksai++;
				if (countreksai % 3 == 0) {
					NangSao(G[i]->getName(), countreksai);
					i = G.size() - 1;
				}
			}
			if (x == 3) {
				G[i] = new Sivir();
				G[i]->Input();
				sivir = 1;
				countsivir++;
				if (countsivir % 3 == 0) {
					NangSao(G[i]->getName(), countsivir);
					i = G.size() - 1;
				}
			}
			if (x == 4) {
				G[i] = new Illaoi();
				G[i]->Input();
				illaoi = 1;
				countillaoi++;
				if (countillaoi % 3 == 0) {
					NangSao(G[i]->getName(), countillaoi);
					i = G.size() - 1;
				}
			}
			n--;
		}
	}
	void KichHeToc() {
		int TocTienCong = reksai + illaoi;
		int TocCongNghe = jarvan + sivir;
		int DauSi = jarvan + reksai + illaoi;
		if (TocTienCong == 2) {
			TocTienCong = 30;
		}
		else
			TocTienCong = 0;
		if (TocCongNghe == 2) {
			TocCongNghe = 15;
		}
		else
			TocCongNghe = 0;
		if (DauSi >= 2) {
			DauSi = (DauSi - 1) * 15;
		}
		else
			DauSi = 0;
		for (int i = 0; i < G.size(); i++) {
			if (G[i]->getName() == "Jarvan") {
				G[i]->setDefend(G[i]->getDefend() + DauSi + TocCongNghe);
				G[i]->setAttack(G[i]->getAttack() + TocCongNghe);
			}
			if (G[i]->getName() == "Reksai" || G[i]->getName() == "Illaoi") {
				G[i]->setDefend(G[i]->getDefend() + DauSi);
				G[i]->setAttack(G[i]->getAttack() + TocTienCong);
			}
			if (G[i]->getName() == "Sivir") {
				G[i]->setDefend(G[i]->getDefend() + TocCongNghe);
				G[i]->setAttack(G[i]->getAttack() + TocCongNghe);
			}
		}
	}
	void NangSao(string name, int count) {
		int dem = 0;
		int vt = 0;
		for (int i = 0; i < G.size(); i++) {
			if (G[i]->getName() == name && G[i]->getStar() == 1) {
				dem++;
				if (dem == 1) {
					vt = i;
				}
				if (dem == 2) {
					G[vt]->setAttack((G[vt]->getAttack() + G[i]->getAttack() + G[G.size() - 1]->getAttack()) * 2);
					G[vt]->setDefend((G[vt]->getDefend() + G[i]->getDefend() + G[G.size() - 1]->getDefend()) * 2);
					G[vt]->setStar(2);
					G.erase(G.begin() + i);
					G.pop_back();
					break;
				}
			}
		}
		if (count % 9 == 0) {
			dem = 0;
			int vtCon2saoThu3 = vt;
			vt = 0;
			for (int i = 0; i < G.size(); i++) {
				if (G[i]->getName() == name && G[i]->getStar() == 2) {
					dem++;
					if (dem == 1) {
						vt = i;
					}
					if (dem == 2) {
						G[vt]->setAttack((G[vt]->getAttack() + G[i]->getAttack() + G[vtCon2saoThu3]->getAttack()) * 3);
						G[vt]->setDefend((G[vt]->getDefend() + G[i]->getDefend() + G[vtCon2saoThu3]->getDefend()) * 2);
						G[vt]->setStar(3);
						G.erase(G.begin() + i);
						G.pop_back();
						break;
					}
				}
			}
		}
	}
	void Output() {
		KichHeToc();
		for (int i = 0; i < G.size(); i++) {
			cout << G[i]->getName() << " - sat thuong gay ra: " << G[i]->Damage(m);
			cout << endl;
		}
	}
};

int main() {
	TFT T;
	T.Input();
	T.Output();
	return 0;
}