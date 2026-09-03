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

### [Demo video (PuTTY)]
<img width="500" alt="Ally+Enemy_0903_demo" src="https://github.com/user-attachments/assets/7f271c24-264f-4c07-aec5-d2ca53fb16c0" />  

### [Folder tree]
```text
├── Docs
│   └── Jamming project summary.pdf
├── Firmware
│   ├── Ally
│   │   └── STM32CubeIDE
│   │       └── jamming
│   │           ├── Core/
│   │           ├── Drivers/
│   │           ├── STM32F429ZITX_FLASH.ld
│   │           ├── STM32F429ZITX_RAM.ld
│   │           └── ally_jamming.ioc
│   └── Enemy
│       └── STM32CubeIDE
│           └── jamming
│               ├── Core/
│               ├── Drivers/
│               ├── STM32F429ZITX_FLASH.ld
│               ├── STM32F429ZITX_RAM.ld
│               └── enemy_jamming.ioc
├── KiCad_project/
├── LIG_SSEN_Jamming.code-workspace
└── README.md
```  

### [Sequence Diagram]

```mermaid
sequenceDiagram
    autonumber
    actor Operator
    participant AllyMCU as Ally STM32
    participant AllyRF as Ally nRF24
    participant EnemyMCU as Enemy STM32
    participant EnemyRF as Enemy nRF24 TX/RX
    participant PuTTY

    Note over AllyMCU,EnemyRF: System initialization
    AllyMCU->>AllyRF: Set first channel and stop carrier
    EnemyMCU->>EnemyRF: Configure TX/RX on channel 78 (2478 MHz)

    Note over EnemyMCU,PuTTY: Verify normal Enemy communication
    loop Every 500 ms
        EnemyMCU->>EnemyRF: Transmit test packet
        EnemyRF-->>EnemyMCU: Deliver received packet
        EnemyMCU->>PuTTY: Print TX=n, RX=n
    end

    Operator->>AllyMCU: Press user button
    AllyMCU->>AllyRF: Start constant carrier
    AllyMCU->>PuTTY: Jamming ON
    AllyMCU->>PuTTY: Channel : 2402 MHz
    Note right of AllyMCU: Green LED OFF<br/>Red LED ON

    par Ally representative channel sweep
        loop 10 channels, 2 seconds per channel
            AllyMCU->>AllyRF: Stop carrier
            AllyMCU->>AllyRF: Set next channel and start carrier
            AllyMCU->>PuTTY: Channel : xxxx MHz
        end
    and Enemy packet measurement
        loop Every 500 ms, up to 1000 packets
            EnemyMCU->>EnemyRF: Transmit test packet on channel 78
            alt Packet received normally
                EnemyRF-->>EnemyMCU: Deliver RX packet
                EnemyMCU->>PuTTY: TX increases, RX increases
            else RX affected on matching channel
                EnemyRF--xEnemyMCU: RX packet missing
                EnemyMCU->>PuTTY: TX increases, RX unchanged
            end
        end
    end

    Operator->>AllyMCU: Press user button again
    AllyMCU->>AllyRF: Stop carrier and channel sweep
    AllyMCU->>PuTTY: Jamming OFF
    Note right of AllyMCU: Green LED ON<br/>Red LED OFF

    Operator->>PuTTY: Compare TX/RX between OFF and ON
```

### [Circuit diagram]
[1] LIG_SSEN_Jamming\Firmware\Common\jamming
- Function : 1개의 STM 보드에 NRF 2개의 모듈을 사용하여, SPI 통신을 통해 Tx 모듈에서 나온 신호를 Rx 모듈로 받아 터미널에서 출력
- Verification results : PASS (2026-07-27)
<img width="500" alt="image" src="https://github.com/user-attachments/assets/e717b052-0da2-4df3-9ebd-f588dc9b0d19" />
