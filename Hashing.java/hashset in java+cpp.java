IN JAVA
-------------------------------------------------------------------------
import java.util.*;
import java.util.HashSet;   // HASHSET IS PRESENT  UTIL PACKAGE
public class hashset {
    
    public static void main(String args[])
    {

    HashSet<Integer> hash=new HashSet<>();         //HASHSET DECLARATION
 hash.add(10);                                     //ADDING ELEMENTS
 hash.add(20);
 hash.add(30);
 hash.add(40);
 hash.add(20);                               // NOT ADDD TO HASHSET AS 20 IS ALREADY PRESENT IN IT
 hash.remove(20);                            //REMOVING THE ELEMENT
 hash.add(500);
//  hash.clear();                            //IT CLEARS THE ALL DATA OF HASHSET
      
System.out.println(hash.size());             //GIVES THE SIZE OF HASHSET
      
 if(hash.contains(50))                      // CONTAINS USED FOR  SEARCHING IN HASHSET
 {
    System.out.println("yes present");
 }
 else
    System.out.print("not present");

for(int i:hash) // FOR EACH LOOP FOR PRINTING ALL ELEMENTS
{  
    System.out.println(" "+i);
}
    
    }
}




IN C++
  --------------------------------------------------------------------------------------------------------------------------------
  
  #include <iostream>
#include <unordered_set>   //hashset in c++ lies inside unordered_set library
using namespace std;

int main(){
    unordered_set<string> set;           //hashset declaration
    set.insert("ASUS");
    set.insert("vivo");
    set.insert("book");
    set.insert("14");
  cout<<set.size()<<endl;                 //gives the size of the set
         for(string i : set)                   //for printing all elements
             cout<<" "<<i;

  // for(auto i=set.begin();i!=set.end();i++)
  // cout<<(*i)<<" ";

    set.erase("14");                                //removes the elements from the hashset
  
  if(set.find("vivo")==set.end())                                         // for searching the element
     cout<<"element not found in this set";
  else
    cout<<endl<<"element present";
 return 0;
}
