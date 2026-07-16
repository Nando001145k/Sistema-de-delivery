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

    class preparable {
        <<interface>>
        +prepare() void*
    }

    class product {
        <<abstract>>
        #string name_
        #double price_
        +calculate_price() double*
        +display() void
    }

    class food {
        +calculate_price() double
        +display() void
        +prepare() void
    }

    class beverage {
        <<final>>
        +calculate_price() double
        +display() void
    }

    class order_item {
        -product* product_
        -int quantity_
        +calculate_subtotal() double
    }

    class order {
        -int id_
        -customer customer_
        -vector items_
        +add_item(product*, int) void
        +calculate_total() double
    }

    product <|-- food : Herança
    product <|-- beverage : Herança
    preparable <|-- food : Implementa
    
    order "1" *-- "1..*" order_item : Composicao
    order "1" o-- "1" customer : Agregacao
    order_item "*" o-- "1" product : Agregacao
```

# Herança Avançada

A classe `beverage` (bebida) foi marcada com a palavra-chave `final`[cite: 1]. Isso garante, em nível de design, que nenhuma outra classe possa herdar dela[cite: 1]. No domínio deste sistema de delivery, uma bebida representa o nível máximo de especialização de um produto pronto (não requerendo subcategorias complexas de preparação como a comida), protegendo o sistema contra extensões indevidas dessa classe[cite: 1].

# Relações e Ciclo de Vida

*   **Composição** (`order` $--$ `order_item`): A classe dona (`order`) cria os itens dependentes internamente. Se o pedido for destruído, os itens do pedido deixam de existir.
*   **Agregação** (`order` $\circ--$ `customer` e `order_item` $\circ--$ `product`): Os clientes e produtos existem independentemente no sistema de delivery, mesmo que um pedido específico seja deletado.
