#include "pokemon.h"

Pokemon::Pokemon(string name, int id, int level, int HP, int ATK, int DEF, int SPE, string ability, PkmnTypes type1, 
        PkmnTypes type2, vector<Move*> *moveset, vector<Move*> *movepool, PkmnStatus Status
        ):name(name),id(id),level(level),ability(ability),type1(type1),type2(type2),HP(HP),ATK(ATK),DEF(DEF),
        SPE(SPE),moveset(moveset),movepool(movepool),Status(Status)
        {
            startStats();
}

// =============== GETTERS ===============
const string Pokemon::getName() const{ return name; }

const int Pokemon::getId() const{ return id; }

const int Pokemon::getLevel() const{ return level; }

const string Pokemon::getAB() const{ return ability; }

const PkmnStatus Pokemon::getStatus() const{ return Status; }

const PkmnTypes Pokemon::getType1() const{ return type1; }

const PkmnTypes Pokemon::getType2() const{ return type2; }

string Pokemon::getStatusString(){ return statusString(Status); }

// ----------- HP -----------
const int Pokemon::getMaxHP() const{ return max_hp; }

const int Pokemon::getHP() const{ return cur_hp; }

const int Pokemon::get_baseHP() const{ return HP; }

// ----------- ATK -----------
const int Pokemon::getATK() const{ return cur_atk; }

const int Pokemon::get_baseATK() const{ return ATK; }

const int Pokemon::getATKchange() const{ return atk_stat_change; }

// ----------- DEF -----------
const int Pokemon::getDEF() const{ return cur_def; }

const int Pokemon::get_baseDEF() const{ return DEF; }

const int Pokemon::getDEFchange() const{ return def_stat_change; }

// ----------- SPE -----------
const int Pokemon::getSPE() const{ return cur_spe; }

const int Pokemon::get_baseSPE() const{ return SPE; }

const int Pokemon::getSPEchange() const{ return spe_stat_change; }

// ---------- MOVES ----------
vector<Move*> *Pokemon::getMoveset(){ return moveset; }

vector<Move*> *Pokemon::getMovepool(){ return movepool; }

// =============== SETTERS ===============
void Pokemon::setLevel(const int &lvl){ level = lvl; }

void Pokemon::setStatus(PkmnStatus status){ Status = status; }

// ----------- HP -----------
void Pokemon::setCurrentHP(const int &HP){ cur_hp=HP; }

// ----------- ATK -----------
void Pokemon::setATKChange(const int &change){ atk_stat_change = change; }

// ----------- DEF -----------
void Pokemon::setDEFChange(const int &change){ def_stat_change = change; }

// ----------- SPE -----------
void Pokemon::setSPEChange(const int &change){ spe_stat_change = change; }

// ---------- MOVES ----------
void Pokemon::setMoveset(vector<Move*> *moveset){ Pokemon::moveset = moveset; }

// =============== METHODS ===============
void Pokemon::startStats(){
    calcATK = (0.01*(2*ATK+36)*level) + 5;
    calcDEF = (0.01*(2*DEF+36)*level) + 5;
    calcSPE = (0.01*(2*SPE+36)*level) + 5;
    max_hp = (0.01*(2*HP+36)*level) + level + 10;

    cur_atk = calcATK;
    cur_def = calcDEF;
    cur_spe = calcSPE;
    cur_hp = max_hp;
}

void Pokemon::updateStats()
{
    if(atk_stat_change != 0){
        switch(atk_stat_change){
            case -6:
                cur_atk = calcATK * 0.25;
            break;
            case -5:
                cur_atk = calcATK * 0.285;
            break;
            case -4:
                cur_atk = calcATK * 0.333;
            break;
            case -3:
                cur_atk = calcATK * 0.4;
            break;
            case -2:
                cur_atk = calcATK * 0.5;
            break;
            case -1:
                cur_atk = calcATK * 0.666;
            break;
            case 1:
                cur_atk = calcATK * 1.5;
            break;
            case 2:
                cur_atk = calcATK * 2;
            break;
            case 3:
                cur_atk = calcATK * 2.5;
            break;
            case 4:
                cur_atk = calcATK * 3;
            break;
            case 5:
                cur_atk = calcATK * 3.5;
            break;
            case 6:
                cur_atk = calcATK * 4;
            break;
        }
    }
    if(def_stat_change != 0){
        switch(def_stat_change){
            case -6:
                cur_def = calcDEF * 0.25;
            break;
            case -5:
                cur_def = calcDEF * 0.285;
            break;
            case -4:
                cur_def = calcDEF * 0.333;
            break;
            case -3:
                cur_def = calcDEF * 0.4;
            break;
            case -2:
                cur_def = calcDEF * 0.5;
            break;
            case -1:
                cur_def = calcDEF * 0.666;
            break;
            case 1:
                cur_def = calcDEF * 1.5;
            break;
            case 2:
                cur_def = calcDEF * 2;
            break;
            case 3:
                cur_def = calcDEF * 2.5;
            break;
            case 4:
                cur_def = calcDEF * 3;
            break;
            case 5:
                cur_def = calcDEF * 3.5;
            break;
            case 6:
                cur_def = calcDEF * 4;
            break;
        }
    }
    if(spe_stat_change != 0){
        switch(spe_stat_change){
            case -6:
                cur_spe = calcDEF * 0.25;
            break;
            case -5:
                cur_spe = calcDEF * 0.285;
            break;
            case -4:
                cur_spe = calcDEF * 0.333;
            break;
            case -3:
                cur_spe = calcDEF * 0.4;
            break;
            case -2:
                cur_spe = calcDEF * 0.5;
            break;
            case -1:
                cur_spe = calcDEF * 0.666;
            break;
            case 1:
                cur_spe = calcDEF * 1.5;
            break;
            case 2:
                cur_spe = calcDEF * 2;
            break;
            case 3:
                cur_spe = calcDEF * 2.5;
            break;
            case 4:
                cur_spe = calcDEF * 3;
            break;
            case 5:
                cur_spe = calcDEF * 3.5;
            break;
            case 6:
                cur_spe = calcDEF * 4;
            break;
        }
    }
    
    switch (Status){
    case PkmnStatus::PARALYZED:
        cur_spe /= 2;
        break;
    case PkmnStatus::BURNED:
        cur_atk /= 2;
        break;
    }
}

void Pokemon::boost(int stat, int amount){
    switch(stat){
        case 1:
            atk_stat_change += amount;
        break;
            
        case 2:
            def_stat_change += amount;
        break;

        case 3:
            spe_stat_change += amount;
        break;
    }
}

// ---------- PRINTERS ----------
void Pokemon::printMoveset(){
    for(auto mve: *moveset){
        mve->printMove();
    }
}

string Pokemon::printData(){
    string data = "\tPokemon: "+name+"\n"
    "\tLevel: "+to_string(level)+"\n"
    "\tType 1: " + typeString(type1)+"\n"
    "\tType 2: " + typeString(type2)+"\n"
    "\tAbility: "+ability+"\n"
    "\tStatus: "+statusString(Status)+"\n"
    "\tHp: "+to_string(cur_hp)+"/"+to_string(max_hp)+"\n"
    "\tAttack: "+to_string(cur_atk)+"\n"
    "\tDefense: "+to_string(cur_def)+"\n"
    "\tSpeed: "+to_string(cur_spe)+"\n"
    "\tAtk Modifier: "+to_string(atk_stat_change)+"\n"
    "\tDefense Modifier: "+to_string(def_stat_change)+"\n"
    "\tSpeed Modifier: "+to_string(spe_stat_change)+"\n";
    return data;
}

void Pokemon::mostrar(){
    cout << "\n-------------" << endl;
    cout << getName() << "\tID: " << getId() << endl;
    cout << "\nLevel: " << getLevel() << "\t";
    cout << "HP: " << getHP() << "\t";
    cout << "ATK: " << getATK() << "\t";
    cout << "DEF: " << getDEF() << "\t";
    cout << "SPE: " << getSPE() << endl;
    cout << "\nTypes: ";
    cout << typeString(getType1());
    if(typeString(getType2()) != "NONE"){
        cout << ", " << typeString(getType2());
    }
    cout << "\tAbility: " << getAB() << endl;
    cout << "\nMoves: \t name \t power \t acc \t pp's \t type" << endl;
    for(auto m: *moveset){
        cout << "\t" << m->getName() << "\t" << m->getPower() << "\t" << m->getAccurracy() << "\t" << m->getPP() << "\t" << typeString(m->getMoveType()) << endl;
    }
    cout<<endl;
}

string Pokemon::statusString(PkmnStatus status){
    switch(status){
        case PkmnStatus::FROZEN:
            return "FRZ";
        break;
        case PkmnStatus::BURNED:
            return "BRN";
        break;
        case PkmnStatus::POISONED:
            return "PSN";
        break;
        case PkmnStatus::BADLY_POISONED:
            return "PSN";
        break;
        case PkmnStatus::PARALYZED:
            return "PAR";
        break;
        case PkmnStatus::SLEEP:
            return "SLP";
        break;
        case PkmnStatus::CONFUSED:
            return "CFD";
        break;
        case PkmnStatus::ATTRACTED:
            return "ATT";
        break;
        case PkmnStatus::HEALTHY:
            return "";
        break;
    }
    return "";
}

string Pokemon::typeString(PkmnTypes tipo){
    switch(tipo){
        case PkmnTypes::BUG:
            return "BUG";
        break;
        case PkmnTypes::DARK:
            return "DARK";
        break;
        case PkmnTypes::DRAGON:
            return "DRAGON";
        break;
        case PkmnTypes::ELECRTRIC:
            return "ELECRTRIC";
        break;
        case PkmnTypes::FAIRY:
            return "FAIRY";
        break;
        case PkmnTypes::FIGHTING:
            return "FIGHTING";
        break;
        case PkmnTypes::FIRE:
            return "FIRE";
        break;
        case PkmnTypes::FLYING:
            return "FLYING";
        break;
        case PkmnTypes::GHOST:
            return "GHOST";
        break;
        case PkmnTypes::GRASS:
            return "GRASS";
        break;
        case PkmnTypes::GROUND:
            return "GROUND";
        break;
        case PkmnTypes::ICE:
            return "ICE";
        break;
        case PkmnTypes::NORMAL:
            return "NORMAL";
        break;
        case PkmnTypes::POISON:
            return "POISON";
        break;
        case PkmnTypes::PSYCHIC:
            return "PSYCHIC";
        break;
        case PkmnTypes::ROCK:
            return "ROCK";
        break;
        case PkmnTypes::STEEL:
            return "STEEL";
        break;
        case PkmnTypes::WATER:
            return "WATER";
        break;
        default:
            return "NONE";
        break;
    }
    return "";
}