class Item{
  private: 
    uint8_t _order, _instruction;
  public:
    Item(uint8_t order, uint8_t instruction){
      _order = order;
      _instruction = instruction;
    }
    uint8_t getOrder(){
      return _order;
    }
  
    uint8_t getInstruction(){
      return _instruction;
    }
};

class MenuItem{
  private:
    uint8_t _count;
    Item* _itemPtr;

  public:
    MenuItem(uint8_t itemCount, Item* itemPtr){
      _count = itemCount;
      _itemPtr = itemPtr;
    }
  
    uint8_t getItemCount(){
      return _count;
    }
  
    Item* getItemsPtr(){
      return _itemPtr;
    }   
};

class Menu{
  private: MenuItem* _menuItemPtr;
  public: 
    static const uint8_t Count = 3;
    
    Menu(MenuItem* menuItemPtr){
      _menuItemPtr = menuItemPtr;
    }
};
