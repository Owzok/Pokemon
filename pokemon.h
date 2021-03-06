#include "typeEffectivenessDB.cpp"

class Pokemon{
    private:
// ----------- IDENTIFIERS -----------
        int id;
        int level;
        string name;
// ----------- STATS -----------
        int max_hp;

        int HP, ATK, DEF, SPA, SPD, SPE;

        int calcATK, calcDEF, calcSPA, calcSPD, calcSPE;

        int cur_hp, cur_atk, cur_def, cur_spa, cur_spd, cur_spe;

        int atk_stat_change = 0, def_stat_change = 0, spa_stat_change = 0, spd_stat_change = 0, spe_stat_change = 0;

        int hp_ev, atk_ev, def_ev, spa_ev, spd_ev, spe_ev;

        int hp_iv, atk_iv, def_iv, spa_iv, spd_iv, spe_iv;

// ----------- DATA -----------
        string ability;

        PkmnTypes type1, type2;
        
        // 4 ataques del pokemon para atacar
        vector<Move*> moveset;

        // total de ataques del pokemon para escoger en la creacion
        vector<Move*> movepool;

        PkmnStatus Status = HEALTHY;

    public:
        Pokemon(string name, int id, int level, int HP, int ATK, int DEF, int SPA, int SPD, int SPE, string ability, PkmnTypes type1, 
        PkmnTypes type2, vector<Move*> moveset, vector<Move*> movepool
        );

// =============== GETTERS ===============
        const string getName() const;
        const int getId() const;
        const int getLevel() const;
        string getStatusString();
        const string getAB() const;
        const PkmnTypes getType1() const;
        const PkmnTypes getType2() const;
        const PkmnStatus getStatus() const;

// ----------- HP -----------
        const int getMaxHP() const;
        const int getHP() const;
        const int get_baseHP() const;

// ----------- ATK -----------
        const int getATKchange() const;
        const int get_baseATK() const;
        const int getATK() const;

// ----------- DEF -----------
        const int getDEFchange() const;
        const int get_baseDEF() const;
        const int getDEF() const;

// ----------- SPA -----------
        const int getSPAchange() const;
        const int get_baseSPA() const;
        const int getSPA() const;

// ----------- SPD -----------
        const int getSPDchange() const;
        const int get_baseSPD() const;
        const int getSPD() const;

// ----------- SPE -----------
        const int getSPEchange() const;
        const int get_baseSPE() const;
        const int getSPE() const; 

// ---------- MOVES ----------
        vector<Move*> getMoveset();
        vector<Move*> getMovepool();

// =============== SETTERS ===============
        void setLevel(const int &level);
        void setStatus(PkmnStatus status);

// ----------- HP -----------
        void setCurrentHP(const int &hp);

// ----------- ATK -----------
        void setATKChange(const int &change);

// ----------- DEF -----------
        void setDEFChange(const int &change);

// ----------- SPA -----------
        void setSPAChange(const int &change);

// ----------- SPD -----------
        void setSPDChange(const int &change);

// ----------- SPE -----------
        void setSPEChange(const int &change);

// ---------- MOVES ----------
        void setMoveset(vector<Move*> moveset);

// =============== METHODS ===============
        void startStats();
        void updateStats();
        void boost(int stat, int amount);

// ---------- PRINTERS ----------
        void printMoveset();
        string printData();
        void mostrar();

// -------- CONVERTERS --------
        string statusString(PkmnStatus status);
        string typeString(PkmnTypes tipo);
};