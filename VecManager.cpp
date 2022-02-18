#include "VecManager.hpp"

int VecManager::Run()
{
    Vector a(0.0, 0.0), b(0.0, 0.0), c(0.0, 0.0), d(0.0, 0.0);
    std::string command = "help";
    while (command != "exit")
    {
        if (command == "dist")
            a.PrintDistance(b);
        else if (command == "help")
            VecManager::help();
        else if (command == "movad")
            a = d;
        else if (command == "movbd")
            b = d;
        else if (command == "movdc")
            d = c;
        else if (command == "rab")
            cin >> a >> b;
        else if (command == "ra")
            cin >> a;
        else if (command == "rb")
            cin >> b;
        else if (command == "pra")
            a.EnterAsPolar();
        else if (command == "prb")
            b.EnterAsPolar();
        else if (command == "outa")
            a.PrintInfoTest();
        else if (command == "outb")
            b.PrintInfo();
        else if (command == "outc")
            c.PrintInfo();
        else if (command == "add")
            c = a + b;
        else if (command == "sub")
            c = a - b;
        else if (command == "mul")
            c = a * b;
        else if (command == "div")
            c = a.Div(b);
        else if (command == "scaleA")
            a = a.Mul(VecManager::CustomInput("Enter a Value: "));
        else if (command == "scaleB")
            b = b.Mul(VecManager::CustomInput("Enter a Value: "));
        else if (command == "magndiff")
            a.PrintMagnDiference(b);
        else if (command == "mov_acc_a")
            a = c;
        else if (command == "mul_n_mov_acc_a")
        {
            c = a * b;
            a = c;
        }
        else {
            cout << "unknown command, try another one\n";
        }
        cout << "Enter a command:  ";
        cout << "\t\t\t\t------\n";
        cin >> command;

    }
    return 0;
}

void VecManager::help()
{
    cout << "Enter:\n";
    cout << "  \"dist\" to find distance\n\n";
    cout << "  \"mul\" or \n";
    cout << "  \"div\" to multiply or divide \n\n";

    cout << "  \"add\" or \n ";
    cout << "  \"sub\" to add or subtract two numbers \n\n";

    cout << "  \"rab\" to rewrite a and b \n";
    cout << "  \"ra\" or \"rb\" to rewrite a or b\n\n";
    cout << "  \"pra\" or \"prb\" to rewrite a or b as polar\n\n";

    cout << "  \"outa\",\"outb\",\"outc\" to print number on console\n";
    cout << "  \"help\" to print this again\n\n\n";


    cout << "So you can input here \'a\' and \'b\'."
        << "\nThen specify operation you'd like me to perform\n";

    cout << "result will be stored in \'c\'."
        << "\nYou can not input in c directly."
        << "\nIt's kinda like accumulator in CPU\n\n";
    cout << endl;
}

double VecManager::CustomInput(std::string prompt)
{
    cout << prompt;
    double out;
    cin >> out;
    return out;
}
