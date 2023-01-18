#ifndef _game
#define _game

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

#include "room.hpp"
#include "bathroom.hpp"
#include "hospitalMorgue.hpp"
#include "operatingRoom.hpp"
#include "block.hpp"
#include "reception.hpp"
#include "ICU.hpp"
#include "restSlut.hpp"
#include "ExtraSlut.hpp"
#include "patient.hpp"

using namespace std;
using namespace sf;

class game
{
    private:

        RenderWindow *Window;
        VideoMode VMode;
        Event event;

        void initVar ();
        void initWindow ();

        array<block, 300> shapes;
        vector<pair<unsigned int, unsigned int>> wall_positions_front;
        vector<pair<unsigned int, unsigned int>> wall_positions_back;
        vector<pair<unsigned int, unsigned int>> wall_positions_down;
        vector<pair<unsigned int, unsigned int>> wall_positions_up;

        operatingRoom operatingRoomO;
        hospitalMorgue hospitalMorgueO;
        bathroom MenBathroom;
        bathroom WomenBathroom;
        reception receptionO;
        ICU ICUO;
        restSlut restSlutO;
        ExtraSlut ExtraSlut1;
        ExtraSlut ExtraSlut2;
        array<patient, 144> patientO;

        unsigned int IndexPatient = 0;

        unsigned int RandomNumber;
        unsigned int MaleOrFemale;
        unsigned int MaleName;
        unsigned int FemaleName;

        int score = 0;
        bool isIn1 = false;
        bool isIn2 = false;
        bool isIn3 = false;
        bool isIn4 = false;
        bool isIn5 = false;
        bool isIn6 = false;
        bool isIn7 = false;

        struct patientInf patientInfO;

        ofstream file;

        Texture shape1;
        Sprite shape_main1;
        Texture shape2;
        Sprite shape_main2;

    public:

        game ();
        ~game ();

        bool isOpen () { return this->Window->isOpen(); }

        void pollEvent ();
        void update ();
        void Render ();

        void drawShapes (Sprite);
        void writeText (string, unsigned int, unsigned int, unsigned int);

        void initBlocks ();
        void initOperatingRoom ();
        void initHospitalMorgue ();
        void initBathroom ();
        void initReception ();
        void initICU ();
        void initRestSlut ();
        void initExtraSlut ();
        void initPatient ();
        void initShapes ();

        void initpatient_right ();
        void initpatient_left ();
        void initpatient_up ();
        void initpatient_down ();

        void initFile ();

        //void initName ();

        void generate_RandomNum ();
        unsigned int get_RandomNum1 ();
        unsigned int get_RandomNum2 ();
        unsigned int get_RandomNum3 ();
        unsigned int get_RandomNum4 ();
        unsigned int get_RandomNum5 ();

        void print_patientInf ();

        int get_score () const { return score; }
};

#endif
