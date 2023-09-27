import os
from pathlib import Path
import gradio as gr
from llama_index import LLMPredictor, GPTVectorStoreIndex, PromptHelper, ServiceContext, StorageContext, load_index_from_storage
from langchain.chat_models import ChatOpenAI
from langchain.callbacks.streaming_stdout import StreamingStdOutCallbackHandler

# Set your OpenAI API key here
os.environ["OPENAI_API_KEY"] = 'XXXXX'

# Global variables
index = None

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
    response = ""
    for letter in ''.join(bot_response.response):
        response += letter + ""
        yield chat_history + [(user_input, response)]

# Gradio setup
with gr.Blocks(css="footer {visibility: hidden}") as demo:
    gr.Markdown('Health Advice Database')
    load_index()

    with gr.Tab("Chatbot"):
        chatbot = gr.Chatbot()
        message = gr.Textbox()
        message.submit(chat, [chatbot, message], chatbot)

demo.queue().launch(share=False)
