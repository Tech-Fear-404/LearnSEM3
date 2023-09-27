import pandas
loader = PandasCSVReader()
documents = loader.load_data(file=Path('./health.csv'))

index = GPTVectorStoreIndex.from_documents(documents,llm_predictor=llm_predictor,prompt_helper=prompt_helper)
import os
os.environ["OPENAI_API_KEY"] = 'XXXXX'

from pathlib import Path
from llama_index import LLMPredictor, GPTVectorStoreIndex, PromptHelper, ServiceContext
from llama_index import StorageContext, load_index_from_storage
from langchain.chat_models import ChatOpenAI
from langchain.callbacks.streaming_stdout import StreamingStdOutCallbackHandler
import gradio as gr

def load_index():
    global index
    llm_predictor = LLMPredictor(
        llm=ChatOpenAI(
            streaming=True,
            callbacks=[StreamingStdOutCallbackHandler()],
            temperature=0,
            model_name="gpt-3.5-turbo",
            max_tokens=2000
        )
    )

 

    max_input_size = 4096
    max_chunk_overlap = 0.2
    chunk_size_limit = 60
    num_outputs = 2000
    prompt_helper = PromptHelper(max_input_size, num_outputs, max_chunk_overlap, chunk_size_limit=chunk_size_limit)
    service_context = ServiceContext.from_defaults(llm_predictor=llm_predictor)
    storage_context = StorageContext.from_defaults(persist_dir="./storage")
    index = load_index_from_storage(storage_context, service_context=service_context)

 

def chat(chat_history, user_input):
  query_engine = index.as_query_engine()
  question = user_input
  bot_response = query_engine.query(question)
  #print("Q:",user_input)
  response = ""
  for letter in ''.join(bot_response.response): #[bot_response[i:i+1] for i in range(0, len(bot_response), 1)]:
      response += letter + ""
      yield chat_history + [(user_input, response)]
  #print("A:",response)

 
with gr.Blocks(css="footer {visibility: hidden}") as demo:
    gr.Markdown('health advice database)')
    load_index()

    with gr.Tab("chatbot"):
          chatbot = gr.Chatbot()
          message = gr.Textbox ()
          message.submit(chat, [chatbot, message], chatbot)

demo.queue().launch(share= False)