enum patientFor {BADPOS, NEEDSURGERY, NEEDREST, DEAD, NEEDWC, WAIT};

struct patientInf
{
    string name = "ali";
    string sex;
    unsigned int Age;
    enum patientFor patientForO;
};