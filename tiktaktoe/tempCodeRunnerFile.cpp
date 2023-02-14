   }
   void take_turn(){
      while (!is_winner( ) || !filled_up()){
         set_position();
         update_board();
         change_player();
         draw();