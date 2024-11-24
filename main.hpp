#include <vector>
#include <string>

typedef struct {
    std::string name; // Nome do ingrediente (array de char)
    int currentQnt;       // Quantidade atual do ingrediente em estoque
} storage_t;

typedef struct {
    std::string name; // Nome da poção (array de char)
    int ingredientIndex[7];    // Array de índices para os ingredientes necessários
    int necessaryQnt[7];    // Array com a quantidade de cada ingrediente necessário
} recipe_t;

void checkIngredients(std::vector<storage_t>* ingredientsStored);
void preparePotion(std::vector<storage_t>* storeIngredients, std::vector<recipe_t>* recipeIngredients);
void mainMenu(std::vector<storage_t>* storeIngredients, std::vector<recipe_t>* recipeIngredients);
void potionHandler(std::vector<storage_t>* storeIngredients, std::vector<recipe_t>* recipeIngredients, int potionIndex);
void restockIngredients(std::vector<storage_t>* storeIngredients);