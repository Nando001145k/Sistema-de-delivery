# Sistema-de-delivery

**Nome:** Luis Fernando De araújo Oliveira.
**Matricula:** 20250019090.

**Descrição de dominio:** O sistema gerencia cliente, produtos do cardapio e o processamento de pedidos, permitindo a adição de varios itens com quantidades específicas e o calculo do valor total da comprar.

# Diagrama UML

```mermaid
classDiagram
    class customer {
        -string name_
        -string address_
        +get_name() string
    }

    class product {
        -int id_
        -string name_
        -double price_
        +get_price() double
        +get_name() string
    }

    class order_item {
        -shared_ptr~product~ product_
        -int quantity_
        +calculate_subtotal() double
    }

    class order {
        -int id_
        -shared_ptr~customer~ customer_
        -vector~unique_ptr~order_item~~ items_
        +add_item(shared_ptr~product~, int) void
        +calculate_total() double
    }

    order "1" *-- "1..*" order_item : Composição (contém)
    order "1" o-- "1" customer : Agregação (pertence a)
    order_item "*" o-- "1" product : Agregação (referencia)
    
```

#Relações e Ciclo de Vida

**Composição** (order -- order_item): A classe dona (order) cria os itens dependentes internamente. Se o pedido for destruído, os itens do pedido deixam de existir.

**Agregação** (order o-- customer e order_item o-- product): Os clientes e produtos existem independentemente no sistema de delivery, mesmo que um pedido específico seja deletado.