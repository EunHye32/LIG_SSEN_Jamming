# LIG_SSEN_Jamming
- Side project : Make jamming signal. 

### [Team member]
- Eunhye Kim (김은혜)
- Ohreum Yoon (윤오름) 

### [Board and Module]
- Main Board : STM32F429I-DISC1
- Module : NRF24L01+PA+LNA 무선 트랜시버 RF 트랜시버 모듈 2.4GHz
- etc. : Capacitor 10uF/100uF, 리튬 이온 배터리 3.7V

### [Hardware images]  
- Ally
<img width="500" alt="image" src="https://github.com/user-attachments/assets/6ef3bdfb-f2a7-42bb-aad3-09eb66247dc5" />  
- Ally + Enemy
<img width="500" alt="Ally+Enemy" src="https://github.com/user-attachments/assets/096a9ddc-a845-4bd9-93a3-5cc15e1f0845" />  

### [Rules of Engagement Flowchart(ROE Flowchart)]
<img width="500" alt="Jamming" src="https://github.com/user-attachments/assets/0ee23b81-2ad6-4733-9b73-2d7c3a819589" />  

### [Circuit diagram]
[1] LIG_SSEN_Jamming\Firmware\Common\jamming
- Function : 1개의 STM 보드에 NRF 2개의 모듈을 사용하여, SPI 통신을 통해 Tx 모듈에서 나온 신호를 Rx 모듈로 받아 터미널에서 출력
- Verification results : PASS (2026-07-27)
<img width="500" alt="image" src="https://github.com/user-attachments/assets/e717b052-0da2-4df3-9ebd-f588dc9b0d19" />
