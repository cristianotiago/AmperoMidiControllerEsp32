Controlador MIDI para Ampero Stomp 2:

1 - Controlar bancos para cima ou para baixo

2 - Ativar Afinador

3 - Controlar Pedais no modo Stomp

4 - Presets + Cenarios 

5 - Conexão para 2 pedais de expresão volume e para controlar efeitos(apenas expressão volume removido por conta de bugs midi da ampero)

6 - Pedais de expresão virtuais


Obs: Pedal de Volume removido por conta de um bug da implementação midi encotrado na documentação

1 - Migração para esp32 WROOM para poder usar sqlite para armazenar o modo cenarios e ter maior velocidade etc...



->modo cenario

->banco basico
->adicionar numero cc data do patches internos


CREATE TABLE amperosc (id INTEGER,a1,a2,a3,a4,a5,a6,b1,b2,b3,b4,b5,b6);
INSERT INTO amperosc VALUES (1, 0,0,0,0,0,0,0,0,0,0,0,0,0);
INSERT INTO amperosc VALUES (2, 0,0,0,0,0,0,0,0,0,0,0,0,0);
INSERT INTO amperosc VALUES (3, 0,0,0,0,0,0,0,0,0,0,0,0,0);
INSERT INTO amperosc VALUES (4, 0,0,0,0,0,0,0,0,0,0,0,0,0);
INSERT INTO amperosc VALUES (5, 0,0,0,0,0,0,0,0,0,0,0,0,0);
INSERT INTO amperosc VALUES (6, 0,0,0,0,0,0,0,0,0,0,0,0,0);
INSERT INTO amperosc VALUES (7, 0,0,0,0,0,0,0,0,0,0,0,0,0);
INSERT INTO amperosc VALUES (8, 0,0,0,0,0,0,0,0,0,0,0,0,0);
INSERT INTO amperosc VALUES (9, 0,0,0,0,0,0,0,0,0,0,0,0,0);
INSERT INTO amperosc VALUES (10, 0,0,0,0,0,0,0,0,0,0,0,0,0);
INSERT INTO amperosc VALUES (11unrea shooting
, 0,0,0,0,0,0,0,0,0,0,0,0,0);