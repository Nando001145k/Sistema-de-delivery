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
        -product product_
        -int quantity_
        +calculate_subtotal() double
    }

    class order {
        -int id_
        -customer customer_
        -vector items_
        +add_item(product, int) void
        +calculate_total() double
    }

    order "1" *-- "1..*" order_item : Composicao
    order "1" o-- "1" customer : Agregacao
    order_item "*" o-- "1" product : Agregacao
```

#Relações e Ciclo de Vida

**Composição** (order -- order_item): A classe dona (order) cria os itens dependentes internamente. Se o pedido for destruído, os itens do pedido deixam de existir.

**Agregação** (order o-- customer e order_item o-- product): Os clientes e produtos existem independentemente no sistema de delivery, mesmo que um pedido específico seja deletado.