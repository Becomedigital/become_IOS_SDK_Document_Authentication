# Documentación de Become iOS SDK

Proceso de instalación de la librería become_IOS_SDK.

## Agregar Alamofire al proyecto
Se debe agregar la librería **Alamofire** al proyecto, click [aqui](https://github.com/Alamofire/Alamofire) para la documentación. 

## Agregar Blinkid al proyecto

 1. Se debe agregar la librería **blinkid** al proyecto, click [aqui](https://github.com/BlinkID/blinkid-ios) para la documentación. 

 2. agregar archivo de texto **com.become.key.txt** con licencia

 <p align="center">
  <img src="https://github.com/Becomedigital/become_IOS_SDK/blob/master/IMG_4.png">
 </p>
 
  3. El [`Bundle Identifier`](https://developer.apple.com/documentation/appstoreconnectapi/bundle_ids) del proyecto debe coincidir con la licencia asignada al cliente 

## Agregar Frameowrk al proyecto
Se debe agregar el archivo **BecomeDigitalV.framework**  en  las configuraciones generales del proyecto en la sección **framework, libraries, and embedded content**:

<p align="center">
  <img src="https://github.com/Becomedigital/become_IOS_SDK/blob/master/IMG_1.png">
</p>
 
Para el correcto funcionamiento de la SDK, se requiere el uso del framework o librería **Alamofire.framework**, el cual se debe adicionar en la sección **framework, libraries, and embedded content**:
 
 <p align="center">
  <img src="https://github.com/Becomedigital/become_IOS_SDK/blob/master/IMG_2.png">
</p>

## Configuraciones dentro de info.plist 

La SDK requiere que dentro de las configuraciones **info.plis**, se encuentre una descripción de uso de la cámara:

    Privacy - Camera Usage Description ( Esta aplicación hace uso de tu cámara)
    
 <p align="center">
  <img src="https://github.com/Becomedigital/become_IOS_SDK/blob/master/IMG_3.png">
 </p>
 
## Inicialización de la SDK

**1. Importar el SDK en nuestro viewController:**

        import  BecomeDigitalV


**2. En el método **startSDKAction ()** de su **viewController** de aplicación, inicialice Become para la captura de imágenes, se debe asignar el **ItFirstTransaction** como True, puedes utilizar el siguiente fragmento de código:**
 
      @IBAction func startSDKAction(_ sender: Any) {
               let dateFormatter = DateFormatter()
               dateFormatter.locale = Locale(identifier: "es_ES") // date user identification
               dateFormatter.dateFormat = "yyyyMMddHHmmssSSS"
               userID = userId.text!.isEmpty ? dateFormatter.string(from: Date()) : userId.text!
               let bdivConfig = BDIVConfig(token:"your_bearer_token",
                                 contractId:  "your_contract_id",
                                 userId: userID,
                                 ItFirstTransaction: true,
                                 customLocalizationFileName: "localize_test")
               BDIVCallBack.sharedInstance.register(bdivConfig: bdivConfig)
       }
                    

**3. En el método **secondAction ()** de su **viewController** de aplicación, inicialice Become y proceda al el envío de la imagen del documento para su posterior validación, se debe asignar el **ItFirstTransaction** como False, Y el parámetro imagen debe estar cargado con la información de la imagen completa por el anverso del documento, puedes utilizar el siguiente fragmento de código:**
 
     @IBAction func secondAction(_ sender: Any) {
        lblResponse.text = "Enviando segunda petición..."
        let bdivConfig = BDIVConfig(token: token.text!,
                                    contractId: "your_contract_id",
                                    userId: userID,
                                    ItFirstTransaction: false,
                                    imgData: (responseIV.fullFronImage?.pngData())!) // Image path, returned by the first event
        BDIVCallBack.sharedInstance.register(bdivConfig: bdivConfig)
    }
    
 
 ## Cambiar textos predeterminados en la SDK     

Para cambiar algún texto predeterminado y asignar uno en reemplazo de este, cree un archivo .string ejemplo: `localize_test.strings` en su proyecto y agrege la eqtiqueta del texto a remplazar ejemplo: `"blinkid_generic_message" = "Su texto aca";`, luego agregue el atributo `customLocalizationFileName` con el nombre del archivo strings en el objeto `BDIVConfig`.

Con `Localize_test.string.string` abierto, en el inspector de archivos toque el botón "Localizar..." y seleccione Inglés.

    @IBAction func startSDKAction(_ sender: Any) {
             let dateFormatter = DateFormatter()
             dateFormatter.locale = Locale(identifier: "es_ES") // date user identification
             dateFormatter.dateFormat = "yyyyMMddHHmmssSSS"
             userID = userId.text!.isEmpty ? dateFormatter.string(from: Date()) : userId.text!
             let bdivConfig = BDIVConfig(token:"your_bearer_token",
                               contractId:  "your_contract_id",
                               userId: userID,
                               ItFirstTransaction: true,
                               customLocalizationFileName: "localize_test")
             BDIVCallBack.sharedInstance.register(bdivConfig: bdivConfig)
     }


## Respuesta de la SDK 
**1. Estructura encargada de la definición del estado de validación exitoso:**

La SDK dará respuesta mediante dos métodos o promesas de respuesta, que pertenecen al estructura  **BDIVDelegate**:

    	func BDIVResponseSuccess(bdivResult: AnyObject) {       
    		        let idmResultFinal = bdivResult as! ResponseIV        
    		       print(String(describing: idmResultFinal))           
    	}        
    
    	func BDIVResponseError(error: String) { 
    	       print(error)   
    	 }

## Estructura para el retorno de la información

Los siguientes parámetros permiten el retorno de la información capturada por el sistema mediante la promesa de respuesta o evento **BDIVResponseSuccess**:

    func BDIVResponseSuccess(bdivResult: AnyObject) {       
    		   let responseIV = bdivResult as! ResponseIV        
    		   
          if(responseIV.IsFirstTransaction){
            btnSecont.isHidden = false
            lblResponse.text = String(describing: responseIV)
            self.imgFront.image = responseIV.frontImage
            self.imgBack.image = responseIV.backImage
            self.imgFullBack.image = responseIV.fullBackImage
            self.imgFullFront.image = responseIV.fullFronImage
        }else{
            lblResponse.text = String(describing: responseIV.documentValidation)
        }         
    }        

Si el parámetro **IsFirstTransaction**, es True, nos indica que es un retorna de la primera transacción, donde se obtiene la imágene que se debe enviar al segundo consumo.


## Objeto para el retorno de la información
Los siguientes parámetros permiten el retorno de la información capturada por el sistema:

    public enum typeEstatus {
        case SUCCES
        case ERROR
        case PENDING
        case NOFOUND
    }
    
    public var firstName: String
    
    public var lastName: String
    
    public var dateOfExpiry: Date
    
    public var age: Int
    
    public var dateOfBirth: Date
    
    public var mrzText: String
    
    public var sex: String
    
    public var barcodeResult: String
    
    public var barcodeResultData: Data
    
    /// Returns a clipping of the document image
    public var frontImage: UIImage?
    
    /// Returns a clipping of the document image
    public var backImage: UIImage?
    
    /// Return full image of the document image
    public var fullFronImage: UIImage?
    
    /// Return full image of the document image
    public var fullBackImage: UIImage?
    
    public var message: String
    
    /// Returns the results of the document validation.
    /// - returns: `liveness_score`, `quality_score`, `liveness_probability`
    public var documentValidation: [String: Any]
    
    public var responseStatus: typeEstatus = .PENDING
    
    /// Defines if the response comes from the first transaction.
    public var IsFirstTransaction: Bool

## Posibles Errores
**1. Error con parámetros vacíos**
Los siguientes parámetros son necesarios para la activación de la SDK por lo tanto su valor no debe ser vacío.

Parámetro | Valor
------------ | -------------
contractID | String
userID  | String
ItFirstTransaction  | Bool

Mostrará el siguiente error por consola:

    parameters cannot be empty

## Implementación del proceso

Esta sección se encarga de proporcionar el fragmento de código para la implementación final del proceso:

          import UIKit
          import  BecomeDigitalV

              class ViewController: UIViewController {

                  override func viewDidLoad() {
                      super.viewDidLoad()
                  }

                  @IBAction func startSDKAction(_ sender: Any) {
                      let dateFormatter = DateFormatter()
                      dateFormatter.locale = Locale(identifier: "es_ES") // date user identification
                      dateFormatter.dateFormat = "yyyyMMddHHmmssSSS"
                      userID = userId.text!.isEmpty ? dateFormatter.string(from: Date()) : userId.text!
                      let bdivConfig = BDIVConfig(token:"your_bearer_token",
                                        contractId:  "your_contract_id",
                                        userId: userID,
                                        ItFirstTransaction: true)
                      BDIVCallBack.sharedInstance.register(bdivConfig: bdivConfig)
                  }
              }


              extension ViewController: BDIVDelegate{
                  func BDIVResponseSuccess(bdivResult: AnyObject) {
                      let idmResultFinal = bdivResult as! ResponseIV
                      print(String(describing: idmResultFinal))

                  }

                  func BDIVResponseError(error: String) {
                      print(error)
                  }
              }

## Requerimientos
•	Tecnologías
iOS 12 en adelante
•	Alamofire
5.5.0 / Swift Package Manager
