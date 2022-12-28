#include"lists2.h"

int main()
{
    List<int> List1;
    int answer;
    cout << "Enter the num of action you want:\n101.Enter the list.\n1.Checking the list for emptiness\n2.Adding an item to the top of the list\n3.Adding an item to the end of the list\n4.Adding a node in front of the element that the cursor points to\n5.Deleting the first node\n6.Deleting the last node\n7.Deleting the node that the cursor points to\n8.Moving the cursor forward/ backward\n9.Displaying the entire list on the screen\n------------\n0.Stopping work\n";
    cin >> answer;
    while(answer != 0){
        if(answer == 101){
            int length1;
            cout << "Your chose is " << answer << " (Enter the list)\nEnter the length of list:\n";
            cin >> length1;
            List1.new_size(length1);
            cout << "\nEnter the list:\n";
            cin >> List1;
            cout << List1 << endl;
        } else if(answer == 1){
            cout << "Your chose is " << answer << " (Checking the list for emptiness)\n";
            if(List1.is_empty()){
                cout << "\n--the list is empty--\n";
            } else {
                cout << "\n++the list isn't empty++\n";
            }
        } else if(answer == 2){
            cout << "Your chose is " << answer << " (Adding an item to the top of the list)\nEnter the num:\n";
            int num;
            cin >> num;
            List1.add_el_ahead(num);
            cout << List1;
        } else if(answer == 3){
            cout << "Your chose is " << answer << " (Adding an item to the end of the list)\nEnter the num:\n";
            int num;
            cin >> num;
            List1.add_el_back(num);
            cout << List1;
        } else if(answer == 4){ //Adding a node in front of the element that the cursor points to
            int num;
            cout << "Your chose is " << answer << " (Adding a node in front of the element that the cursor points to)\nEnter the num:\n";
            cin >> num;
            List1.add_bef_cur(num);
            cout << List1;
        } else if(answer == 5){ //\n5.Deleting the first node\n
            cout << "Your chose is " << answer << " (Deleting the first node)\n";
            List1.pop_first();
            cout << List1 << endl;
        } else if(answer == 6){ //6.Deleting the last node\n
            cout << "Your chose is " << answer << " (Deleting the last node)\n";
            List1.pop_last();
            cout << List1 << endl;
        } else if(answer == 7){ //7.Deleting the node that the cursor points to\n
            cout << "Your chose is " << answer << " (Deleting the node that the cursor points to)\n";
            List1.pop_curs_nod();
            cout << List1;
        } else if(answer == 8){ //8.Moving the cursor forward/ backward\n
            string dir;
            cout << "Your chose is " << answer << " (Moving the cursor forward/ backward)\nIf you want to move the cursor to the right, write 'r', else 'l':\n";
            cin >> dir;
            if (dir == "r"){
                List1.move_right();
            }else if (dir == "l"){
                List1.move_left();
            } else {
            cout << "-_-_-_-_ERROR_-_-_-_-\n";
            }
            cout << List1;
        } else if(answer == 9){
            cout << "Your chose is " << answer << " (Displaying the entire list on the screen)\n";
            cout << List1 << endl;
        }
        cout << "\nEnter the num of action you want:\n1.Checking the list for emptiness\n2.Adding an item to the top of the list\n3.Adding an item to the end of the list\n4.Adding a node in front of the element that the cursor points to\n5.Deleting the first node\n6.Deleting the last node\n7.Deleting the node that the cursor points to\n8.Moving the cursor forward/ backward\n9.Displaying the entire list on the screen\n------------\n0.Stopping work\n";
        cin >> answer;
    }
    cout << "---You have finished working with the list---\n";
    cout << List1;
    return 0;
}