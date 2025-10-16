# Milestone2 Fract-ol

Este projeto faz parte do currículo da escola 42 e tem como objetivo **explorar a renderização gráfica em tempo real**, utilizando a biblioteca **MiniLibX** para desenhar e manipular fractais.  

📌 O programa deve exibir os fractais **Mandelbrot** e **Julia**, permitindo zoom, movimentação e interação do usuário com o teclado e o mouse.

## 🔧 Regras do Projeto  

- O programa deve exibir um fractal (Mandelbrot ou Julia) em uma janela.  
- O fractal deve responder a eventos de **zoom** e **movimentação**.  
- Para Julia, os parâmetros iniciais são passados pelo terminal.  
- É obrigatório utilizar a biblioteca gráfica **MiniLibX**.  
- Inputs válidos:

```bash
./fractol mandelbrot
./fractol julia <valor1> <valor2>
```
- Os valores de Julia devem ser números válidos (inteiros ou com ponto decimal).
- Em caso de erro, o programa deve exibir mensagens explicativas.

## 🚀 Minha Solução

1. Validação do Input
- Aceito apenas ./fractol mandelbrot ou ./fractol julia <valor1> <valor2>.
- Se o input for inválido, exibo uma mensagem com as opções corretas.
- Para Julia, valido se os valores são numéricos (com ou sem “.”) e converto para double.
- Implementei minha própria função atof para fazer essa conversão.

2 .Inicialização da Janela
Utilizo funções da MiniLibX para:
- Criar conexão com a janela (mlx_init).
- Criar a janela (mlx_new_window).
- Criar a imagem (mlx_new_image).
- Inicializo variáveis de controle na struct principal.

4. Renderização Inicial
- Assim que a janela é criada, renderizo a primeira imagem (Mandelbrot ou Julia).
- O fluxo para printa a imagem na janela: put_image -> color_func -> (if_mandelbrot ou if_julia).
- Color_func decide qual fractal renderizar com base no input.
- As funções if_mandelbrot e if_julia calculam a parte real e imaginária para determinar as cores.

5. Interação com o Mouse (Zoom)
- Uso mlx_mouse_hook para capturar o scroll do mouse.
- Na função mouse_hook:
  - Calculo a intensidade do zoom.
  - Atualizo as coordenadas de referência (x e y).
  - Destruo a imagem anterior (mlx_destroy_image).
  - Recrio e renderizo a nova imagem com o zoom aplicado.

6. Interação com o Teclado (Movimentação e Escape)
- Uso mlx_key_hook para capturar eventos do teclado.
- Na função key_hook:
  - Setas direcionais → movimentam o fractal na tela.
  - ESC → destrói imagem e janela e encerra o programa.
- A cada interação, a imagem antiga é destruída e a nova é renderizada.

7. Fechamento da Janela
- Uso mlx_hook para capturar o clique no “X” da janela.
- Na função close_window, destruo tudo e encerro o programa com segurança.

## 📈 Estratégia

Minha solução prioriza:
- Organização clara do fluxo de execução (input → render → interação).
- Re-renderização eficiente ao interagir com zoom e movimento.
- Separação de responsabilidades: cálculo do fractal, controle de eventos e renderização.
- Conversão robusta de strings para double para permitir flexibilidade nos valores de Julia.

## 🛠️ Como usar

Compilar:
```bash
make
```

Executar Mandelbrot:
```bash
./fractol mandelbrot
```

Executar Julia:
```bash
./fractol julia -0.7 0.27015
```

Controles:
- 🖱️ Scroll → Zoom in/out
- ⬅️ ➡️ ⬆️ ⬇️ → Movimentação
- ⎋ ESC → Fechar programa
- ❌ Clique no X → Encerrar janela
