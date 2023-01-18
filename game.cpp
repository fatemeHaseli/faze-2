#include "game.hpp"

void game::initVar ()
{
    this->Window = nullptr;
}

void game::initWindow ()
{
    this->VMode.height = 1500;
    this->VMode.width = 800;

    this->Window = new RenderWindow (VideoMode (VMode.height, VMode.width), "Hospital", Style::Titlebar | Style::Close); 
    this->Window->setFramerateLimit (45);
    this->Window->setPosition (Vector2i (330, 100));
}

void game::pollEvent ()
{
    bool front = false;
    bool back = false;
    bool up = false;
    bool down = false;

    while (Window->pollEvent (this->event))
    {
        switch (this->event.type)
        {
            case Event::Closed:
                this->Window->close ();
                break;
            
            case Event::KeyReleased:
                if (this->event.key.code == Keyboard::Escape)
                    this->Window->close ();
                break;
            case Event::KeyPressed:
                if (this->event.key.code == Keyboard::Right || this->event.key.code == Keyboard::D)
                {
                    this->initpatient_right ();

                    front = true;
                    back = false;
                    up = false;
                    down = false;
                }
                if (this->event.key.code == Keyboard::Left || this->event.key.code == Keyboard::A)
                {
                    this->initpatient_left ();

                    front = false;
                    back = true;
                    up = false;
                    down = false;
                }
                if (this->event.key.code == Keyboard::Up || this->event.key.code == Keyboard::W)
                {
                    this->initpatient_up ();

                    front = false;
                    back = false;
                    up = true;
                    down = false;
                }
                if (this->event.key.code == Keyboard::Down || this->event.key.code == Keyboard::S)
                {
                    this->initpatient_down ();

                    front = false;
                    back = false;
                    up = false;
                    down = true;
                }
                break;
        }
    }
}

void game::update ()
{
    this->pollEvent ();
}

void game::Render ()
{
    this->Window->display ();

    this->Window->clear (Color (60, 0, 110));

    (*this).drawShapes (operatingRoomO.get_shapeMain ());

    (*this).drawShapes (hospitalMorgueO.get_shapeMain ());

    (*this).drawShapes (MenBathroom.get_shapeMain ());
    (*this).drawShapes (WomenBathroom.get_shapeMain ());

    (*this).drawShapes (receptionO.get_shapeMain ());

    (*this).drawShapes (ICUO.get_shapeMain ());

    (*this).drawShapes (restSlutO.get_shapeMain ());

    (*this).drawShapes (ExtraSlut1.get_shapeMain ());
    (*this).drawShapes (ExtraSlut2.get_shapeMain ());

    for (unsigned int i = 0; i < 300; i++)
    {
        if (i != 30 && i != 31)
        {
            (*this).drawShapes (shapes[i].get_shape_main ());
        }
    }
    this->drawShapes (shape_main1);
    this->drawShapes (shape_main2);

    /*if (this->get_RandomNum1 () == 0)
    {

        if (this->patientO[this->IndexPatient].get_xpos () != operatingRoomO.get_goTo ().first)
        {
            this->initpatient_right ();
        }
        else
        {
            if (this->patientO[this->IndexPatient].get_ypos () != operatingRoomO.get_goTo ().second)
            {
                this->initpatient_up ();
            }
        }
    }
    else if (this->get_RandomNum1 () == 1)
    {
        if (this->patientO[this->IndexPatient].get_xpos () != receptionO.get_goTo ().first)
        {
            this->initpatient_right ();
        }
        else
        {
            if (this->patientO[this->IndexPatient].get_ypos () != receptionO.get_goTo ().second)
            {
                this->initpatient_up ();
            }
        }
    }
    else if (this->get_RandomNum1 () == 2)
    {
        if (this->patientO[this->IndexPatient].get_xpos () != MenBathroom.get_goTo ().first)
        {
            this->initpatient_right ();
        }
        else
        {
            if (this->patientO[this->IndexPatient].get_ypos () != MenBathroom.get_goTo ().second)
            {
                this->initpatient_up ();
            }
        }
    }
    else if (this->get_RandomNum1 () == 3)
    {
        if (this->patientO[this->IndexPatient].get_xpos () != WomenBathroom.get_goTo ().first)
        {
            this->initpatient_right ();
        }
        else
        {
            if (this->patientO[this->IndexPatient].get_ypos () != WomenBathroom.get_goTo ().second)
            {
                this->initpatient_up ();
            }
        }
    }
    else if (this->get_RandomNum1 () == 4)
    {
        if (this->patientO[this->IndexPatient].get_xpos () != hospitalMorgueO.get_goTo ().first)
        {
            this->initpatient_right ();
        }
        else
        {
            if (this->patientO[this->IndexPatient].get_ypos () != hospitalMorgueO.get_goTo ().second)
            {
                this->initpatient_down ();
            }
        }
    }
    else if (this->get_RandomNum1 () == 5)
    {
        if (this->patientO[this->IndexPatient].get_xpos () != ICUO.get_goTo ().first)
        {
            this->initpatient_right ();
        }
        else
        {
            if (this->patientO[this->IndexPatient].get_ypos () != ICUO.get_goTo ().second)
            {
                this->initpatient_down ();
            }
        }
    }
    else if (this->get_RandomNum1 () == 6)
    {
        if (this->patientO[this->IndexPatient].get_xpos () != restSlutO.get_goTo ().first)
        {
            this->initpatient_right ();
        }
        else
        {
            if (this->patientO[this->IndexPatient].get_ypos () != restSlutO.get_goTo ().second)
            {
                this->initpatient_down ();
            }
        }
    }*/

    if (this->get_RandomNum2 () == 0)
    {
        this->patientO[this->IndexPatient].set_sex ("M");

        if (get_RandomNum3 () == 0)
        {
            this->patientO[this->IndexPatient].set_name ("Amir Hossein Hanifi");
        }
        else if (get_RandomNum3 () == 1)
        {
            this->patientO[this->IndexPatient].set_name ("Hossein Hattami");
        }
        else if (get_RandomNum3 () == 2)
        {
            this->patientO[this->IndexPatient].set_name ("Mehdi Rafii");
        }
        else if (get_RandomNum3 () == 3)
        {
            this->patientO[this->IndexPatient].set_name ("Amir Zafari");
        }
    }
    else if (this->get_RandomNum2 () == 1)
    {
        this->patientO[this->IndexPatient].set_sex ("F");

        if (get_RandomNum4 () == 0)
        {
            this->patientO[this->IndexPatient].set_name ("Fateme Haseli");
        }
        else if (get_RandomNum4 () == 1)
        {
            this->patientO[this->IndexPatient].set_name ("Zahra Hassani");
        }
        else if (get_RandomNum4 () == 2)
        {
            this->patientO[this->IndexPatient].set_name ("Fateme Damavandi");
        }
        else if (get_RandomNum4 () == 3)
        {
            this->patientO[this->IndexPatient].set_name ("Bitta Movahedi");
        }
    }

    this->print_patientInf ();

    patientO[IndexPatient].set_Age (get_RandomNum5 ());

    if (patientO[IndexPatient].get_ypos () >= 50 && patientO[IndexPatient].get_ypos () <= 250 && patientO[IndexPatient].get_xpos () >= 50 && patientO[IndexPatient].get_xpos () <= 200)
    {
        if (patientO[IndexPatient].get_patientFor () != "surgery")
        {
            if (this->isIn1 == false)
            {
                score -= 2;
            }

            isIn1 = true;
        }
        }
        else if (patientO[IndexPatient].get_patientFor () == "surgery")
        {
            pair<unsigned int, unsigned int> availablePlaceC = operatingRoomO.get_availabePlace ();

            score += 5;

            if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
            {
                availablePlaceC = ExtraSlut1.get_availabePlace ();

                if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
                {
                    availablePlaceC = ExtraSlut2.get_availabePlace ();
                }
            }

            patientO[IndexPatient].set_pos (availablePlaceC.first, availablePlaceC.second);

            file << "Name: " << patientO[IndexPatient].get_name () << " sex Type: " << patientO[IndexPatient].get_sex () << " Age: " << patientO[IndexPatient].get_Age () << " patient for: " << patientO[IndexPatient].get_patientFor () << endl;

            this->IndexPatient++;

            this->generate_RandomNum ();

            this->initPatient ();
    }
    else
    {
        isIn1 = false;
    }
    
    if (patientO[IndexPatient].get_ypos () >= 50 && patientO[IndexPatient].get_ypos () <= 250 && patientO[IndexPatient].get_xpos () >= 300 && patientO[IndexPatient].get_xpos () <= 400)
    {
        if (patientO[IndexPatient].get_patientFor () != "needrest")
        {
            if (this->isIn2 == false)
            {
                score -= 2;
            }

            isIn2 = true;
        }
        else if (patientO[IndexPatient].get_patientFor () == "needrest")
        {
            pair<unsigned int, unsigned int> availablePlaceC = receptionO.get_availabePlace ();

            score += 5;

            if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
            {
                availablePlaceC = ExtraSlut1.get_availabePlace ();
                if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
                {
                    availablePlaceC = ExtraSlut2.get_availabePlace ();
                }
            }

            patientO[IndexPatient].set_pos (availablePlaceC.first, availablePlaceC.second);

            file << "Name: " << patientO[IndexPatient].get_name () << " sex Type: " << patientO[IndexPatient].get_sex () << " Age: " << patientO[IndexPatient].get_Age () << " patient for: " << patientO[IndexPatient].get_patientFor () << endl;

            this->IndexPatient++;

            this->generate_RandomNum ();

            this->initPatient ();
        }
    }
    else
    {
        isIn2 = false;
    }
    if (patientO[IndexPatient].get_ypos () >= 50 && patientO[IndexPatient].get_ypos () <= 200 && patientO[IndexPatient].get_xpos () >= 500 && patientO[IndexPatient].get_xpos () <= 550)
    {
        if (patientO[IndexPatient].get_patientFor () != "needWC")
        {
            if (this->isIn3 == false)
            {
                score -= 2;
            }

            isIn3 = true;
        }
        else if (patientO[IndexPatient].get_patientFor () == "needWC")
        {
            if (patientO[IndexPatient].get_sex () == "M")
            {
                score += 5;

                pair<unsigned int, unsigned int> availablePlaceC = MenBathroom.get_availabePlace ();

                if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
                {
                    availablePlaceC = restSlutO.get_availabePlace ();
                    if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
                    {
                        availablePlaceC = ExtraSlut1.get_availabePlace ();
                        if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
                        {
                            availablePlaceC = ExtraSlut2.get_availabePlace ();
                        }
                    }
                }

                patientO[IndexPatient].set_pos (availablePlaceC.first, availablePlaceC.second);

                file << "Name: " << patientO[IndexPatient].get_name () << " sex Type: " << patientO[IndexPatient].get_sex () << " Age: " << patientO[IndexPatient].get_Age () << " patient for: " << patientO[IndexPatient].get_patientFor () << endl;

                this->IndexPatient++;

                this->generate_RandomNum ();

                this->initPatient ();
            }
            else
            {

                if (this->isIn3 == false)
                {
                    score -= 1;
                }

                isIn3 = true;
            }
        }
    }
    else
    {
        isIn3 = false;
    }

    if (patientO[IndexPatient].get_ypos () >= 50 && patientO[IndexPatient].get_ypos () <= 200 && patientO[IndexPatient].get_xpos () >= 650 && patientO[IndexPatient].get_xpos () <= 700)
    {
        if (patientO[IndexPatient].get_patientFor () != "needWC")
        {
            if (this->isIn4 == false)
            {
                score -= 2;
            }

            isIn4 = true;
        }
        else if (patientO[IndexPatient].get_patientFor () == "needWC")
        {
            if (patientO[IndexPatient].get_sex () == "F")
            {
                score += 5;

                pair<unsigned int, unsigned int> availablePlaceC = WomenBathroom.get_availabePlace ();
        
                if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
                {
                    availablePlaceC = restSlutO.get_availabePlace ();
                    if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
                    {
                        availablePlaceC = ExtraSlut1.get_availabePlace ();
                        if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
                        {
                            availablePlaceC = ExtraSlut2.get_availabePlace ();
                        }
                    }
                }

                patientO[IndexPatient].set_pos (availablePlaceC.first, availablePlaceC.second);

                file << "Name: " << patientO[IndexPatient].get_name () << " sex Type: " << patientO[IndexPatient].get_sex () << " Age: " << patientO[IndexPatient].get_Age () << " patient for: " << patientO[IndexPatient].get_patientFor () << endl;

                this->IndexPatient++;

                this->generate_RandomNum ();

                this->initPatient ();
            }
            else
            {
                if (this->isIn4 == false)
                {
                    score -= 1;
                }

                isIn4 = true;
            }
        } 
    }
    else
    {
        isIn4 = false;
    }
    if (patientO[IndexPatient].get_ypos () <= 700 && patientO[IndexPatient].get_ypos () >= 500 && patientO[IndexPatient].get_xpos () >= 50 && patientO[IndexPatient].get_xpos () <= 200)
    {
        if (patientO[IndexPatient].get_patientFor () != "dead")
        {
            if (this->isIn5 == false)
            {
                score -= 2;
            }

            isIn5 = true;
        }
        else if (patientO[IndexPatient].get_patientFor () == "dead")
        {
            score += 5;

            pair<unsigned int, unsigned int> availablePlaceC = hospitalMorgueO.get_availabePlace ();
        
            if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
            {
                availablePlaceC = ExtraSlut1.get_availabePlace ();
                if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
                {
                    availablePlaceC = ExtraSlut2.get_availabePlace ();
                }
            }

            patientO[IndexPatient].set_pos (availablePlaceC.first, availablePlaceC.second);

            file << "Name: " << patientO[IndexPatient].get_name () << " sex Type: " << patientO[IndexPatient].get_sex () << " Age: " << patientO[IndexPatient].get_Age () << " patient for: " << patientO[IndexPatient].get_patientFor () << endl;

            this->IndexPatient++;

            this->generate_RandomNum ();

            this->initPatient ();
        }
    }
    else
    {
        isIn5 = false;
    }
    if (patientO[IndexPatient].get_ypos () <= 700 && patientO[IndexPatient].get_ypos () >= 500 && patientO[IndexPatient].get_xpos () >= 300 && patientO[IndexPatient].get_xpos () <= 450)
    {
        if (patientO[IndexPatient].get_patientFor () != "badpos")
        {
            if (this->isIn6 == false)
            {
                score -= 2;
            }

            isIn6 = true;
        }
        else if (patientO[IndexPatient].get_patientFor () == "badpos")
        {
            score += 5;

            pair<unsigned int, unsigned int> availablePlaceC = ICUO.get_availabePlace ();
        
            if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
            {
                availablePlaceC = ExtraSlut1.get_availabePlace ();
                if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
                {
                    availablePlaceC = ExtraSlut2.get_availabePlace ();
                }
            }

            patientO[IndexPatient].set_pos (availablePlaceC.first, availablePlaceC.second);

            file << "Name: " << patientO[IndexPatient].get_name () << " sex Type: " << patientO[IndexPatient].get_sex () << " Age: " << patientO[IndexPatient].get_Age () << " patient for: " << patientO[IndexPatient].get_patientFor () << endl;

            this->IndexPatient++;

            this->generate_RandomNum ();

            this->initPatient ();
        }
    }
    else
    {
        isIn6 = false;
    }
    if (patientO[IndexPatient].get_ypos () <= 700 && patientO[IndexPatient].get_ypos () >= 500 && patientO[IndexPatient].get_xpos () >= 550 && patientO[IndexPatient].get_xpos () <= 700)
    {
        if (patientO[IndexPatient].get_patientFor () != "wait")
        {
            if (this->isIn7 == false)
            {
                score -= 2;
            }

            isIn7 = true;
        }
        else if (patientO[IndexPatient].get_patientFor () == "wait")
        {
            score += 5;

            pair<unsigned int, unsigned int> availablePlaceC = restSlutO.get_availabePlace ();
        
            if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
            {
                availablePlaceC = ExtraSlut1.get_availabePlace ();
                if (availablePlaceC.first == 0 && availablePlaceC.second == 0)
                {
                    availablePlaceC = ExtraSlut2.get_availabePlace ();
                }
            }

            patientO[IndexPatient].set_pos (availablePlaceC.first, availablePlaceC.second);

            file << "Name: " << patientO[IndexPatient].get_name () << " sex Type: " << patientO[IndexPatient].get_sex () << " Age: " << patientO[IndexPatient].get_Age () << " patient for: " << patientO[IndexPatient].get_patientFor () << endl;

            this->IndexPatient++;

            this->generate_RandomNum ();

            this->initPatient ();
        }
    }
    else
    {
        isIn7 = false;
    }

    switch (this->get_RandomNum1 ())
    {
        case 0:
            patientO[IndexPatient].set_patientFor ("surgery");
            break;
        case 1:
            patientO[IndexPatient].set_patientFor ("needrest");
            break;
        case 2:
            patientO[IndexPatient].set_patientFor ("needWC");
            patientO[IndexPatient].set_sex ("M");

            if (get_RandomNum3 () == 0)
            {
                this->patientO[this->IndexPatient].set_name ("Amir Hossein Hanifi");
            }
            else if (get_RandomNum3 () == 1)
            {
                this->patientO[this->IndexPatient].set_name ("Hossein Hattami");
            }
            else if (get_RandomNum3 () == 2)
            {
                this->patientO[this->IndexPatient].set_name ("Mehdi Rafei");
            }
            else if (get_RandomNum3 () == 3)
            {
                this->patientO[this->IndexPatient].set_name ("Amir Zafari");
            }
            break;
        case 3:
            patientO[IndexPatient].set_patientFor ("needWC");
            patientO[IndexPatient].set_sex ("F");

            if (get_RandomNum4 () == 0)
            {
                this->patientO[this->IndexPatient].set_name ("Fateme Haseli");
            }
            else if (get_RandomNum4 () == 1)
            {
                this->patientO[this->IndexPatient].set_name ("Zahra Hassani");
            }
            else if (get_RandomNum4 () == 2)
            {
                this->patientO[this->IndexPatient].set_name ("Fateme Damavandi");
            }
            else if (get_RandomNum4 () == 3)
            {
                this->patientO[this->IndexPatient].set_name ("Bitta Movahedi");
            }
            break;
        case 4:
            patientO[IndexPatient].set_patientFor ("dead");
            break;
        case 5:
            patientO[IndexPatient].set_patientFor ("badpos");
            break;
        case 6:
            patientO[IndexPatient].set_patientFor ("wait");
            break;
    }

    for (unsigned int i = 0; i < 144; i++) 
    {
        (*this).drawShapes (patientO[i].get_shapeMain ());
    }

    this->writeText ("operating\nRoom", 70, 110, 20);
    this->writeText ("rest-slot", 310, 130, 20);
    this->writeText ("hospital\nmorgue", 80, 630, 20);
    this->writeText ("M-WC", 520, 110, 20);
    this->writeText ("F-WC", 670, 110, 20);
    this->writeText ("ICU", 360, 630, 40);
    this->writeText ("wait-room", 560, 640, 25);
    this->writeText ("Extra-Slot-1", 850, 130, 30);
    this->writeText ("Extra-Slot-2", 850, 640, 30);
}

void game::drawShapes (Sprite temp)
{
    this->Window->draw (temp);
}

void game::initBlocks ()
{
    for (unsigned int i = 0; i < 300; i++)
    {
        shapes[i].set_Texture ("../shape/block.png");
    }

    for (unsigned int i = 0; i < 24; i++)
    {
        shapes[i].set_xpos ((i * 50));
        shapes[i].set_ypos (0);
    }
    for (unsigned int i = 24; i < 40; i++)
    {
        shapes[i].set_xpos (0);
        shapes[i].set_ypos (((i - 23) * 50));
    }
    for (unsigned int i = 40; i < 56; i++)
    {
        shapes[i].set_xpos (1200 - 50);
        shapes[i].set_ypos (((i - 39) * 50));
    }
    for (unsigned int i = 56; i < 79; i++)
    {
        shapes[i].set_xpos (((i - 55) * 50));
        shapes[i].set_ypos (800 - 50);
    }

    for (unsigned int i = 80; i < 84; i++)
    {
        shapes[i].set_xpos (5 * 50);
        shapes[i].set_ypos (((i - 79) * 50));
    }
    for (unsigned int i = 84; i < 88; i++)
    {
        shapes[i].set_xpos (9 * 50);
        shapes[i].set_ypos (((i - 83) * 50));
    }
    for (unsigned int i = 88; i < 91; i++)
    {
        shapes[i].set_xpos (12 * 50);
        shapes[i].set_ypos (((i - 87) * 50));
    }
    for (unsigned int i = 91; i < 95; i++)
    {
        shapes[i].set_xpos (15 * 50);
        shapes[i].set_ypos (((i - 90) * 50));
    }

    for (unsigned int i = 95; i < 99; i++)
    {
        shapes[i].set_xpos (5 * 50);
        shapes[i].set_ypos (((i - 94 + 10) * 50));
    }
    for (unsigned int i = 99; i < 103; i++)
    {
        shapes[i].set_xpos (10 * 50);
        shapes[i].set_ypos (((i - 98 + 10) * 50));
    }
    for (unsigned int i = 103; i < 107; i++)
    {
        shapes[i].set_xpos (15 * 50);
        shapes[i].set_ypos (((i - 102 + 10) * 50));
    }

    for (unsigned int i = 0; i < 300; i++)
    {
        pair < unsigned int, unsigned int> front1;
        pair < unsigned int, unsigned int> front2;

        front1.first = shapes[i].get_xpos ();
        front1.second = shapes[i].get_ypos () + 1;
        front2.first = shapes[i].get_xpos ();
        front2.second = shapes[i].get_ypos () + 49;

        wall_positions_front.push_back (front1);
        wall_positions_front.push_back (front2);

        pair < unsigned int, unsigned int> back1;
        pair < unsigned int, unsigned int> back2;

        back1.first = shapes[i].get_xpos () + 50;
        back1.second = shapes[i].get_ypos () + 1;
        back2.first = shapes[i].get_xpos () + 50;
        back2.second = shapes[i].get_ypos () + 49;

        wall_positions_back.push_back (back1);
        wall_positions_back.push_back (back2);

        pair < unsigned int, unsigned int> up1;
        pair < unsigned int, unsigned int> up2;

        up1.first = shapes[i].get_xpos () + 1;
        up1.second = shapes[i].get_ypos () + 50;
        up2.first = shapes[i].get_xpos () + 49;
        up2.second = shapes[i].get_ypos () + 50;

        wall_positions_up.push_back (up1);
        wall_positions_up.push_back (up2);

        pair < unsigned int, unsigned int> down1;
        pair < unsigned int, unsigned int> down2;

        down1.first = shapes[i].get_xpos () + 1;
        down1.second = shapes[i].get_ypos ();
        down2.first = shapes[i].get_xpos () + 49;
        down2.second = shapes[i].get_ypos ();

        wall_positions_down.push_back (down1);
        wall_positions_down.push_back (down2);
    }
}

void game::initOperatingRoom ()
{
    operatingRoomO.set_Texture ("../shape/operatingRoom.jpg");

    operatingRoomO.set_pos (40, 30);

    operatingRoomO.set_name ("operatingRoom");

    operatingRoomO.set_length (200, 200);

    operatingRoomO.set_capacity (16);

    operatingRoomO.set_availabePlaces ();

    operatingRoomO.goTo ();
}

void game::initHospitalMorgue ()
{
    hospitalMorgueO.set_Texture ("../shape/hospitalMorgue.jpg");

    hospitalMorgueO.set_pos (40, 550);

    hospitalMorgueO.set_length (200, 200);

    hospitalMorgueO.set_capacity (16);

    hospitalMorgueO.set_availabePlaces ();

    hospitalMorgueO.goTo ();
}

void game::initBathroom ()
{
    MenBathroom.set_Texture ("../shape/MenBathroom.jpg");
    WomenBathroom.set_Texture ("../shape/WomenBathroom.jpg");

    MenBathroom.set_pos (490, 30);
    WomenBathroom.set_pos (640, 30);

    MenBathroom.set_name ("MenBathroom");
    WomenBathroom.set_name ("WomenBathroom");

    MenBathroom.set_length (100, 150);
    WomenBathroom.set_length (100, 150);

    MenBathroom.set_capacity (6);
    WomenBathroom.set_capacity (6);

    MenBathroom.set_sex ('M');
    WomenBathroom.set_sex ('F');

    MenBathroom.set_availabePlaces ();
    WomenBathroom.set_availabePlaces ();

    MenBathroom.goTo ();
    WomenBathroom.goTo ();
}

void game::initReception ()
{
    receptionO.set_Texture ("../shape/reception.jpg");

    receptionO.set_pos (290, 30);

    receptionO.set_name ("reception");

    receptionO.set_length (150, 200);

    receptionO.set_capacity (12);

    receptionO.set_availabePlaces ();

    receptionO.goTo ();
}

void game::initICU ()
{
    ICUO.set_Texture ("../shape/ICU.jpg");

    ICUO.set_pos (290, 550);

    ICUO.set_name ("ICU");

    ICUO.set_length (200, 200);

    ICUO.set_capacity (16);

    ICUO.set_availabePlaces ();

    ICUO.goTo ();
}

void game::initRestSlut ()
{
    restSlutO.set_Texture ("../shape/restSlut.jpg");

    restSlutO.set_pos (540, 550);

    restSlutO.set_name ("restSlut");

    restSlutO.set_length (200, 200);

    restSlutO.set_capacity (16);

    restSlutO.set_availabePlaces ();

    restSlutO.goTo ();
}

void game::initExtraSlut ()
{
    ExtraSlut1.set_Texture ("../shape/extraSlut.jpg");
    ExtraSlut2.set_Texture ("../shape/extraSlut.jpg");

    ExtraSlut1.set_pos (790, 30);
    ExtraSlut2.set_pos (790, 550);

    ExtraSlut1.set_name ("ExtraSlut_1");
    ExtraSlut2.set_name ("ExtraSlut_2");

    ExtraSlut1.set_length (350, 200);
    ExtraSlut2.set_length (350, 200);

    ExtraSlut1.set_capacity (28);
    ExtraSlut2.set_capacity (28);

    ExtraSlut1.set_whichOne (1);
    ExtraSlut2.set_whichOne (2);

    ExtraSlut1.set_availabePlaces ();
    ExtraSlut2.set_availabePlaces ();
}

void game::initPatient ()
{
    patientO[IndexPatient].set_Texture ("../shape/patient.jpeg");

    patientO[IndexPatient].set_pos (0, 375);

    patientO[IndexPatient].set_name ("Patient");

    patientO[IndexPatient].set_length (50, 50);

    
}

void game::writeText (string string, unsigned int xpos, unsigned int ypos, unsigned int size)
{
    Font font;

    if (!font.loadFromFile("../font/University.otf"))
    {
        cerr << "Error" << endl;
    }
    Text text;

    text.setString (string);

    text.setFont (font);

    text.setPosition(xpos, ypos);

    text.setFillColor (Color::Black);

    text.setCharacterSize (size);

    Window->draw (text);
}

void game::initpatient_right ()
{
    bool crashed_front = false;

    for (unsigned int i = 0; i < wall_positions_front.size (); i++)
    {
        for (unsigned int j = 0; j < 48; j++)
        {
            if (patientO[IndexPatient].front_position[j].first == wall_positions_front.at (i).first && patientO[IndexPatient].front_position[j].second == wall_positions_front.at (i).second)
            {
                crashed_front = true;
            }
        }
    }

    if (crashed_front == false)
    {
        patientO[IndexPatient].move_x_pos ();
    }

    patientO[IndexPatient].set_direction ("right");
    /*this->writeText (patientO[IndexPatient].get_name (), patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos (), 20);
    this->writeText (patientO[IndexPatient].get_patientFor (), patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 22, 20);
    if (patientO[IndexPatient].get_sex () == "M")
    {
        this->writeText ("Male", patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 44, 20);
    }
    else if (patientO[IndexPatient].get_sex () == "F")
    {
        this->writeText ("Female", patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 44, 20);
    }*/
}
void game::initpatient_left ()
{
    bool crashed_back = false;

    for (unsigned int i = 0; i < wall_positions_back.size (); i++)
    {
        for (unsigned int j = 0; j < 48; j++)
        {
            if (patientO[IndexPatient].back_position[j].first == wall_positions_back.at (i).first && patientO[IndexPatient].back_position[j].second == wall_positions_back.at (i).second)
            {
                crashed_back = true;
            }
        }
    }

    if (crashed_back == false)
    {
        patientO[IndexPatient].move_x_neg ();
    }

    patientO[IndexPatient].set_direction ("left");
    /*this->writeText (patientO[IndexPatient].get_name (), patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos (), 20);
    this->writeText (patientO[IndexPatient].get_patientFor (), patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 22, 20);
    if (patientO[IndexPatient].get_sex () == "M")
    {
        this->writeText ("Male", patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 44, 20);
    }
    else if (patientO[IndexPatient].get_sex () == "F")
    {
        this->writeText ("Female", patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 44, 20);
    }*/
}
void game::initpatient_up ()
{
    bool crashed_up = false;

    for (unsigned int i = 0; i < wall_positions_up.size (); i++)
    {
        for (unsigned int j = 0; j < 48; j++)
        {
            if (patientO[IndexPatient].up_position[j].first == wall_positions_up.at (i).first && patientO[IndexPatient].up_position[j].second == wall_positions_up.at (i).second)
            {
                crashed_up = true;
            }
        }
    }

    if (crashed_up == false)
    {
        patientO[IndexPatient].move_y_neg ();
    }

    patientO[IndexPatient].set_direction ("up");
    /*this->writeText (patientO[IndexPatient].get_name (), patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos (), 20);
    this->writeText (patientO[IndexPatient].get_patientFor (), patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 22, 20);
    if (patientO[IndexPatient].get_sex () == "M")
    {
        this->writeText ("Male", patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 44, 20);
    }
    else if (patientO[IndexPatient].get_sex () == "F")
    {
        this->writeText ("Female", patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 44, 20);
    }*/
}
void game::initpatient_down ()
{
    bool crashed_down = false;

    for (unsigned int i = 0; i < wall_positions_down.size (); i++)
    {
        for (unsigned int j = 0; j < 48; j++)
        {
            if (patientO[IndexPatient].down_position[j].first == wall_positions_down.at (i).first && patientO[IndexPatient].down_position[j].second == wall_positions_down.at (i).second)
            {
                crashed_down = true;
            }
        }
    }

    if (crashed_down == false)
    {
        patientO[IndexPatient].move_y_pos ();
    }

    patientO[IndexPatient].set_direction ("down");
    /*this->writeText (patientO[IndexPatient].get_name (), patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos (), 20);
    this->writeText (patientO[IndexPatient].get_patientFor (), patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 22, 20);
    if (patientO[IndexPatient].get_sex () == "M")
    {
        this->writeText ("Male", patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 44, 20);
    }
    else if (patientO[IndexPatient].get_sex () == "F")
    {
        this->writeText ("Female", patientO[IndexPatient].get_xpos () + 51, patientO[IndexPatient].get_ypos () + 44, 20);
    }*/
}

void game::initFile ()
{
    file.open ("../patientInf.txt", ios::out);
}

void game::initShapes ()
{
    this->shape1.loadFromFile ("../shape/hospitalMorgue.jpg");
    this->shape_main1 = Sprite (shape1);
    this->shape_main1.setPosition (1240, 50);

    this->shape2.loadFromFile ("../shape/restSlut.jpg");
    this->shape_main2 = Sprite (shape2);
    this->shape_main2.setPosition (1240, 300);
}

/*void game::initName ()
{
    RenderWindow *Window2 = nullptr;
    VideoMode Vmode2;
    Event event2;

    this->VMode.height = 200;
    this->VMode.width = 200;

    this->Window = new RenderWindow (VideoMode (VMode.height, VMode.width), "Hospital", Style::Titlebar | Style::Close); 
    this->Window->setFramerateLimit (45);
    this->Window->setPosition (Vector2i (100, 100));
}*/

void game::generate_RandomNum ()
{
    srand((unsigned)time(0));
    this->RandomNumber = (rand() % 7);
    srand((unsigned)time(0));
    this->MaleOrFemale = (rand() % 2);
    srand((unsigned)time(0));
    this->MaleName = (rand() % 4);
    srand((unsigned)time(0));
    this->FemaleName = (rand() % 4);
    srand ((unsigned)time(0));
    this->patientInfO.Age = (rand() % 110);
}
unsigned int game::get_RandomNum1 ()
{
    return this->RandomNumber;
}
unsigned int game::get_RandomNum2 ()
{
    return this->MaleOrFemale;
}
unsigned int game::get_RandomNum3 ()
{
    return this->MaleName;
}
unsigned int game::get_RandomNum4 ()
{
    return this->FemaleName;
}
unsigned int game::get_RandomNum5 ()
{
    return this->patientInfO.Age;
}

void game::print_patientInf ()
{
    string temp, temp2;
    temp += to_string (this->patientO[this->IndexPatient].get_Age ());
    temp2 += to_string (this->get_score ());

    if (this->get_score () < 0)
    {
        temp2 += " M";
    }
    else if (this->get_score () > 0)
    {
        temp2 += " P";
    }

    this->writeText ("patient Name: ", 1245, 55, 20);
    this->writeText (this->patientO[this->IndexPatient].get_name (), 1245, 85, 20);

    this->writeText ("Age: ", 1245, 115, 20);
    this->writeText (temp, 1400, 115, 20);

    this->writeText ("Gender: ", 1245, 145, 20);
    this->writeText (this->patientO[this->IndexPatient].get_sex (), 1400, 145, 20);

    this->writeText ("patient For: ", 1245, 305, 20);
    this->writeText (this->patientO[IndexPatient].get_patientFor (), 1270, 330, 20);

    this->writeText ("score: ", 1270, 410, 20);
    this->writeText (temp2, 1370, 410, 20);
}


game::game ()
{
    this->initVar ();
    this->initWindow ();

    this->initBlocks ();
    this->initOperatingRoom ();
    this->initHospitalMorgue ();
    this->initBathroom ();
    this->initReception ();
    this->initICU ();
    this->initRestSlut ();
    this->initExtraSlut ();
    this->initPatient ();
    this->initFile ();

    this->initShapes ();
}

game::~game ()
{
    delete this->Window;

    file.close ();
}