#include <iostream>
#include <vector>
#include <cstring>
#include "main.hpp"

/*
############################################################################################
                                    INICIALIZA OS VETORES
############################################################################################
*/

void innitializeStoreIngredients(std::vector<storage_t> *storeIngredients){
        *storeIngredients = {
            {"Po de Fenix", 100}, //0
            {"Essencia Celestial", 50}, //1
            {"Raiz de Dragao", 45}, //2
            {"Orvalho Lunar", 30}, //3
            {"Flores secas", 200}, //4
            {"Elixir amargo", 20}, //5
            {"Lagrimas de unicornio", 15} //6
        };
}
void innitializeRecipes(std::vector<recipe_t> *recipeIngredients){
    *recipeIngredients = {
        {"Pocao de cura", {0, 1, 4, 6}, {30, 20, 20, 10}},
        {"Pocao Forca da Floresta", {3, 2, 4}, {20, 30, 30}},
        {"Pocao Sabedoria da Riqueza", {1, 0}, {30, 50}},
        {"Pocao Sorte no Amor", {3, 4, 6}, {10, 50, 5}},
        {"Pocao Malvada", {5, 2}, {10, 15}}
    };
}

/*
############################################################################################
                                    PREPARAÇÃO DAS POÇÕES
############################################################################################
*/

//PRINTA A QUANTIDADE ATUAL DE INGREDIENTES
void checkIngredients(std::vector<storage_t>* ingredientsStored){
    int i = 1;
    for (const auto& ing : *ingredientsStored) {
        std::cout <<i++<< ". Ingrediente: " << ing.name
                  << ", Quantidade: " << ing.currentQnt << std::endl;
    }
    std::cout<<std::endl;
}



//PREPARAÇÃO DE POÇÃO
void preparePotion(std::vector<storage_t>* storeIngredients, std::vector<recipe_t>* recipeIngredients){
    int ans = 0;

    //MENU DE CRIACAO DE POCOES
    std::cout<<"Escolha a pocao que voce deseja criar:"<<std::endl;
    std::cout<<"(1) Pocao de Cura"<<std::endl;
    std::cout<<"(2) Pocao Forca da Floresta"<<std::endl;
    std::cout<<"(3) Pocao Sabedoria da Riqueza"<<std::endl;
    std::cout<<"(4) Pocao Sorte no Amor"<<std::endl;
    std::cout<<"(5) Pocao Malvada"<<std::endl;

    std::cout<<std::endl;

    std::cin>>ans;

    switch(ans){
        case 1:
            potionHandler(storeIngredients, recipeIngredients, (ans-1));
            break;
        case 2:
            potionHandler(storeIngredients, recipeIngredients, (ans-1));
            break;
        case 3:
            potionHandler(storeIngredients, recipeIngredients, (ans-1));
            break;
        case 4:
            potionHandler(storeIngredients, recipeIngredients, (ans-1));
            break;
        case 5:
            potionHandler(storeIngredients, recipeIngredients, (ans-1));
            break;
        default:
            std::cout<<"Opcao invalida, digite uma opcao valida!"<<std::endl;
            preparePotion(storeIngredients, recipeIngredients);
            break;

    }
    
}



//FAZ AS OPERAÇÕES COM OS ITENS DAS POÇÕES

void potionHandler(std::vector<storage_t>* storeIngredients, std::vector<recipe_t>* recipeIngredients, int potionIndex){
    bool isPotionPossible = 1;

    std::cout<<std::endl;
    std::cout<<"Pocao escolhida: "<<(*recipeIngredients)[potionIndex].name<<std::endl;
    std::cout<<std::endl;


//VERIFICA SE PODE FABRICAR A POCAO
    for(int i = 0; i<7; i++){
        if(((*storeIngredients)[(*recipeIngredients)[potionIndex].ingredientIndex[i]].currentQnt) < ((*recipeIngredients)[potionIndex].necessaryQnt[i])){
            if(isPotionPossible == 1){//testa se era possível fabricar a poção

                std::cout<<"Nao foi possivel preparar a pocao. Ingredientes em falta:"<<std::endl;
                isPotionPossible = 0; //define que não é possível fabricar a poção

            }
            std::cout<<(*storeIngredients)[(*recipeIngredients)[potionIndex].ingredientIndex[i]].name<<": necessario: "<<(*recipeIngredients)[potionIndex].necessaryQnt[i]<<", disponivel: "<<(*storeIngredients)[(*recipeIngredients)[potionIndex].ingredientIndex[i]].currentQnt<<std::endl;

        }
    }
    std::cout<<std::endl;




    //DESCONTA OS ITENS SE POSSIVEL: vetorDoEstoqueDeItens[indexDoItemADescontar].quantidadeAtualDaqueleItemNoEstoque -= quantidadeNecessariaDoItem)
    if(isPotionPossible){
        std::cout<<"~*~*~*~*~*~*~*~*~*~*~*~*~*~"<<std::endl;
        std::cout<<" Pocao criada com sucesso!"<<std::endl;
        std::cout<<"~*~*~*~*~*~*~*~*~*~*~*~*~*~"<<std::endl;
        std::cout<<std::endl;

        for(int i = 0; i<7; i++){
            (*storeIngredients)[(*recipeIngredients)[potionIndex].ingredientIndex[i]].currentQnt -= (*recipeIngredients)[potionIndex].necessaryQnt[i];
        }
    }
}




//FAZ O REABASTECIMENTO DOS INGREDIENTES
void restockIngredients(std::vector<storage_t>* storeIngredients){
    int ansIng, ansQnt;

    //recolhe o ingrediente desejado pelo usuário para reabastecimento
    std::cout<<"Qual ingrediente voce deseja reabastecer? Escolha pelo numero."<<std::endl;
    std::cout<<std::endl;
    checkIngredients(storeIngredients);

    std::cin>>ansIng;

    //testa se a resposta cumpre os requisitos
    if((ansIng<=7)&&(ansIng>0)){

        //recolhe a quantidade que o usuário deseja reabastecer
        std::cout<<"Quanto de "<<(*storeIngredients)[ansIng-1].name<<" voce quer colocar no estoque?"<<std::endl;
        std::cin>>ansQnt;
        //valida a resposta do usuário da quantidade a abastecer
        if(ansQnt>0){
            (*storeIngredients)[ansIng-1].currentQnt += ansQnt;
            std::cout<<ansQnt<<" unidades de "<<(*storeIngredients)[ansIng-1].name<<" foram adicionados ao estoque!"<<std::endl;
            std::cout<<std::endl;
            return;

        }else{
            std::cout<<"Uma quantidade invalida foi digitada, digite uma quantidade valida."<<std::endl;
            restockIngredients(storeIngredients);
        }
    }else{
        std::cout<<"Um ingrediente invalido foi escolhido, digite um ingrediente valido."<<std::endl;
        restockIngredients(storeIngredients);

    }

    

}


/*
############################################################################################
                                        MENU PRINCIPAL
############################################################################################
*/


//MENU PRINCIPAL, REDIRECIONA PRA TODAS AS FUNCOES
void mainMenu(std::vector<storage_t>* storeIngredients, std::vector<recipe_t>* recipeIngredients){

    int ans = 0;
    std::cout << "+------------------------------------------------------------+" << std::endl;
    std::cout << "|                                                            |" << std::endl;
    std::cout << "|                SISTEMA DE GERENCIAMENTO                    |" << std::endl;
    std::cout << "|                 DE POCOES DE ALQUIMIA                      |" << std::endl;
    std::cout << "|                                                            |" << std::endl;
    std::cout << "+------------------------------------------------------------+" << std::endl;
 
    std::cout<<"(1) consultar ingredientes disponiveis\n(2) preparar pocao\n(3) reabastecer ingredientes\n(4) sair do programa"<<std::endl;
    std::cin>>ans;

    //verifica a resposta do user
    switch(ans){
        case 1:
            checkIngredients(storeIngredients);
            break;
        case 2:
            preparePotion(storeIngredients, recipeIngredients);
            std::cout<<"Estoque atualizado:"<<std::endl;
            checkIngredients(storeIngredients);
            break;
        case 3:
            restockIngredients(storeIngredients);
            break;
        case 4:
            exit(0);
            break;

    }
    
}





int main(){
    //declara e inicializa os vetores
    std::vector<storage_t> storeIngredients;
    std::vector<recipe_t> recipeIngredients;

    innitializeStoreIngredients(&storeIngredients);
    innitializeRecipes(&recipeIngredients);

    //maquina de estados do programa
    while(1){
        mainMenu(&storeIngredients, &recipeIngredients);
    }
}