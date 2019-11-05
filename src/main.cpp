#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "menu_main.cpp"
#include "GameManager.h"
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <set>
#include "DataManager.h"
//#include "Player.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  bool start_game;
  int player_score;
  start_game = false;
  std::map<string, int> actual_player_map;
  std::string actual_player_name;

  // do{
  // GameManager gm;
  // start_game = gm.InitManager();
  // } while (start_game==true);
while (true){

  while(start_game ==false){
 GameManager gm;
  start_game = gm.InitManager();

  }
  start_game = false;
Player *newplayer = new Player();
DataManager *newdm = new DataManager();
newplayer->SetPlayerName();


 std::cout<<"begin the game"<<std::endl;
  

  //get_user_data();



  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
 
  std::cout << "INFO. Game has terminated successfully!\n\n";
 
  std::cout<<"-----------------------------------"<<std::endl;
  std::cout<<"-----------------------------------"<<std::endl;
  actual_player_name = newplayer->GetPlayerName();
  std::cout<<" PLAYER Name  ::  "<< actual_player_name << std::endl;
  std::cout << "Score: " << game.GetScore() << "\n";
  player_score = game.GetScore();
  std::cout << "Size: " << player_score << "\n";
  
  //std::cout<<"NAME :::::::::::::::::::" << newplayer->GetPlayerName();
  actual_player_map.insert(std::make_pair(actual_player_name, player_score));
  newdm->WriteGameHistoryMap(actual_player_map);

}
  return 0;
}